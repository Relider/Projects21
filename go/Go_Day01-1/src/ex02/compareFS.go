package main

import (
	"bufio"
	"crypto/md5"
	"encoding/hex"
	"flag"
	"fmt"
	"log"
	"os"
)

func generateMD5Hash(text string) string {
	hasher := md5.New()
	hasher.Write([]byte(text))
	return hex.EncodeToString(hasher.Sum(nil))
}

func err_code(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func getHashmap(filename string) map[string]string {
	file, err := os.Open(filename)
	err_code(err)
	defer file.Close()

	hashmap := make(map[string]string)
	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		text := scanner.Text()
		hash := generateMD5Hash(text)
		hashmap[hash] = text
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	return hashmap
}

func CompareSnapshots(snapshot1, snapshot2 string) {
	hashmap := getHashmap(snapshot1)
	file, err := os.Open(snapshot2)
	err_code(err)
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		path := scanner.Text()
		hash := generateMD5Hash(path)
		if _, exists := hashmap[hash]; exists {
			delete(hashmap, hash)
		} else {
			fmt.Println("ADDED", path)
		}
	}

	for _, path := range hashmap {
		fmt.Println("REMOVED", path)
	}
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
	oldsnapshot, newsnapshot := get_filename()
	CompareSnapshots(oldsnapshot, newsnapshot)
}
