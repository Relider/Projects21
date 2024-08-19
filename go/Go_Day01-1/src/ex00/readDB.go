package main

import (
	"encoding/json"
	"encoding/xml"
	"fmt"
	"log"
	"os"
	"strings"
)

type Recipes struct {
	Cakes []struct {
		Name        string `json:"name" xml:"name"`
		Time        string `json:"time" xml:"stovetime"`
		Ingredients []struct {
			Name  string `json:"ingredient_name" xml:"itemname"`
			Count string `json:"ingredient_count" xml:"itemcount"`
			Unit  string `json:"ingredient_unit,omitempty" xml:"itemunit"`
		} `json:"ingredients" xml:"ingredients>item"`
	} `json:"cake" xml:"cake"`
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
	text, err := os.ReadFile(s.filename)
	err_code(err)
	err = xml.Unmarshal(text, &recipes)
	err_code(err)
	return
}

func printToConsole(recipes Recipes, DBR DBReader) {
	if _, ok := DBR.(*xmlReader); ok {
		jsonData, err := json.MarshalIndent(recipes, "", "    ")
		err_code(err)
		fmt.Println(string(jsonData))
	} else {
		xmlData, err := xml.MarshalIndent(recipes, "", "    ")
		err_code(err)
		fmt.Println(xml.Header + string(xmlData))
	}

}

func get_filename() (DBR DBReader) {
	if strings.HasSuffix(os.Args[2], ".json") {
		jsonReader := new(jsonReader)
		jsonReader.filename = os.Args[2]
		DBR = jsonReader
	} else if strings.HasSuffix(os.Args[2], ".xml") {
		xmlReader := new(xmlReader)
		xmlReader.filename = os.Args[2]
		DBR = xmlReader
	}
	return
}

func error_test() {
	if len(os.Args) != 3 {
		log.Fatal("Wrong number of arguments")
	}
	if os.Args[1] != "-f" {
		log.Fatal("You should use -f flag to specify the file")
	}
}

func main() {
	error_test()
	DBR := get_filename()
	recipes := DBR.parseFile()
	printToConsole(recipes, DBR)
}
