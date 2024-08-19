package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"os"
	"sync"
)

var countMap map[string]int
var wg sync.WaitGroup

func errorFlagsCase() {
	if len(os.Args) < 2 {
		log.Fatal("Invalid number of arguments")
	}
}

func btou(b bool) uint8 {
	var result uint8 = 0
	if b {
		result = 1
	}
	return result
}

func flagParser(w, l, m bool) (string, int) {
	flag := "w"
	flagpoint := 2
	if btou(w)+btou(l)+btou(m) > 1 {
		log.Fatal("You can only use one flag -w -l or -m")
	}
	if !w && !l && !m {
		flagpoint = 1
	} else if m {
		flag = "m"
	} else if l {
		flag = "l"
	}
	return flag, flagpoint
}

func err_test(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func count(file string, flag string) {
	f, err := os.Open(file)
	err_test(err)
	defer f.Close()

	scanner := bufio.NewScanner(f)
	switch flag {
	case "w":
		scanner.Split(bufio.ScanWords)
	case "l":
		scanner.Split(bufio.ScanLines)
	case "m":
		scanner.Split(bufio.ScanRunes)
	}
	c := 0
	for scanner.Scan() {
		c++
	}
	countMap[file] = c
	wg.Done()
}

func consolePrint(files []string) {
	for _, f := range files {
		fmt.Printf("%d\t%s\n", countMap[f], f)
	}
}

func goStart(files []string, flag string) {
	wg.Add(len(files))
	for _, file := range files {
		go count(file, flag)
	}
	wg.Wait()
	consolePrint(files)
}

func main() {
	wPtr := flag.Bool("w", false, "count words")
	lPtr := flag.Bool("l", false, "count lines")
	mPtr := flag.Bool("m", false, "count runes")
	flag.Parse()

	errorFlagsCase()
	flag, flagPoint := flagParser(*wPtr, *lPtr, *mPtr)
	countMap = make(map[string]int)
	goStart(os.Args[flagPoint:], flag)
}
