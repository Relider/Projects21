package main

import (
	"encoding/json"
	"encoding/xml"
	"flag"
	"fmt"
	"log"
	"os"
	"strings"
)

type Ingredients struct {
	Name  string `json:"ingredient_name" xml:"itemname"`
	Count string `json:"ingredient_count" xml:"itemcount"`
	Unit  string `json:"ingredient_unit,omitempty" xml:"itemunit"`
}

type Cakes struct {
	Name        string        `json:"name" xml:"name"`
	Time        string        `json:"time" xml:"stovetime"`
	Ingredients []Ingredients `json:"ingredients" xml:"ingredients>item"`
}

type Recipes struct {
	Cakes []Cakes `json:"cake" xml:"cake"`
}

type DBReader interface {
	parseFile() (recipes Recipes)
}

type jsonReader struct {
	filename string
}

type xmlReader struct {
	filename string
}

func err_code(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func (s jsonReader) parseFile() (recipes Recipes) {
	text, err := os.ReadFile(s.filename)
	err_code(err)
	err = json.Unmarshal(text, &recipes)
	err_code(err)
	return
}

func (s xmlReader) parseFile() (recipes Recipes) {
	fmt.Println(s.filename)
	text, err := os.ReadFile(s.filename)
	err_code(err)
	err = xml.Unmarshal(text, &recipes)
	err_code(err)
	return
}

func get_type(filename string) (DBR DBReader) {
	if strings.HasSuffix(filename, ".xml") {
		xml := new(xmlReader)
		xml.filename = filename
		DBR = xml
	} else if strings.HasSuffix(filename, ".json") {
		json := new(jsonReader)
		json.filename = filename
		DBR = json
	} else {
		log.Fatal("ERROR: Неподдерживаемый формат")
	}
	return
}

func cycles(oldCakesMap map[string]Cakes, newCakesMap map[string]Cakes, callback func(Cakes, Cakes)) {
	for name, newRecipe := range newCakesMap {
		if oldRecipe, exists := oldCakesMap[name]; exists {
			callback(oldRecipe, newRecipe)
		}
	}
}

func CompareCaces(oldCakesMap map[string]Cakes, newCakesMap map[string]Cakes) {
	for name := range newCakesMap {
		if _, exists := oldCakesMap[name]; !exists {
			fmt.Printf("ADDED cake \"%s\"\n", name)
		}
	}
	for name := range oldCakesMap {
		if _, exists := newCakesMap[name]; !exists {
			fmt.Printf("REMOVED cake \"%s\"\n", name)
		}
	}
}

func CompareTime(oldRecipe Cakes, newRecipe Cakes) {
	if oldRecipe.Time != newRecipe.Time {
		fmt.Printf("CHANGED cooking time for cake \"%s\" - \"%s\" instead of \"%s\"\n", newRecipe.Name, newRecipe.Time, oldRecipe.Time)
	}
}

func CompareIngredients(oldRecipe Cakes, newRecipe Cakes) {
	oldIngredientsMap := map[string]Ingredients{}
	for _, ingredient := range oldRecipe.Ingredients {
		oldIngredientsMap[ingredient.Name] = ingredient
	}

	for _, newIngredient := range newRecipe.Ingredients {
		_, exists := oldIngredientsMap[newIngredient.Name]
		if !exists {
			fmt.Printf("ADDED ingredient \"%s\" for cake \"%s\"\n", newIngredient.Name, newRecipe.Name)
		} else {
			delete(oldIngredientsMap, newIngredient.Name)
		}
	}

	for name := range oldIngredientsMap {
		fmt.Printf("REMOVED ingredient \"%s\" for cake \"%s\"\n", name, oldRecipe.Name)
	}
}

func CompareUnits(oldRecipe Cakes, newRecipe Cakes) {
	oldIngredientsMap := map[string]Ingredients{}
	for _, ingredient := range oldRecipe.Ingredients {
		oldIngredientsMap[ingredient.Name] = ingredient
	}

	for _, newIngredient := range newRecipe.Ingredients {
		oldIngredient, oldexists := oldIngredientsMap[newIngredient.Name]
		if oldexists {
			if oldIngredient.Unit != newIngredient.Unit {
				if newIngredient.Unit != "" {
					fmt.Printf("CHANGED unit for ingredient \"%s\" for cake \"%s\" - \"%s\" instead of \"%s\"\n", newIngredient.Name, newRecipe.Name, newIngredient.Unit, oldIngredient.Unit)
				} else {
					fmt.Printf("REMOVED unit \"%s\" for ingredient \"%s\" for cake \"%s\"", oldIngredient.Unit, newIngredient.Name, newRecipe.Name)
				}
			} else if oldIngredient.Count != newIngredient.Count {
				fmt.Printf("CHANGED unit count for ingredient \"%s\" for cake \"%s\" - \"%s\" instead of \"%s\"\n", newIngredient.Name, newRecipe.Name, newIngredient.Count, oldIngredient.Count)
			}
		}
	}
}

func CompareDatabases(oldRecipes Recipes, newRecipes Recipes) {
	oldCakesMap := map[string]Cakes{}
	newCakesMap := map[string]Cakes{}

	for _, Cakes := range oldRecipes.Cakes {
		oldCakesMap[Cakes.Name] = Cakes
	}
	for _, Cakes := range newRecipes.Cakes {
		newCakesMap[Cakes.Name] = Cakes
	}

	CompareCaces(oldCakesMap, newCakesMap)
	cycles(oldCakesMap, newCakesMap, CompareTime)
	cycles(oldCakesMap, newCakesMap, CompareIngredients)
	cycles(oldCakesMap, newCakesMap, CompareUnits)
}

func get_filename() (string, string) {
	oldFile := flag.String("old", "", "Путь к оригинальному файлу базы данных (XML или JSON)")
	newFile := flag.String("new", "", "Путь к новому файлу базы данных (XML или JSON)")

	flag.Parse()

	if *oldFile == "" || *newFile == "" {
		log.Fatal("Error: Не указаны пути к файлам")
	}

	return *oldFile, *newFile
}

func main() {
	oldfilename, newfilename := get_filename()

	oldreader := get_type(oldfilename)
	newreader := get_type(newfilename)

	oldrecipes := oldreader.parseFile()
	newrecipes := newreader.parseFile()

	CompareDatabases(oldrecipes, newrecipes)
}
