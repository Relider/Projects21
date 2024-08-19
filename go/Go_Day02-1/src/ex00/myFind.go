package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"strings"
)

func noFlagsCase(filesPtr *bool, dirsPtr *bool, linksPtr *bool) {
	if !*filesPtr && !*dirsPtr && !*linksPtr {
		*filesPtr = true
		*dirsPtr = true
		*linksPtr = true
	}
}

func errorFlagsCase(f bool, ext string) {
	if len(os.Args) < 2 {
		log.Fatal("You haven't specify the path")
	}
	if _, err := os.Open(os.Args[len(os.Args)-1]); err != nil {
		log.Fatal("There is no such file or directory")
	}
	if !f && ext != "" {
		log.Fatal("erroneous use of flag \"ext\"")
	}
}

func err_code(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func dCase(d bool, path string, filename string) {
	if d {
		fmt.Println(path + filename)
	}
}

func lCase(l bool, path string, filename string, link string) {
	_, errLink := os.Open(path + link)
	if l && errLink != nil {
		fmt.Printf("%s -> %s\n", path+filename, "[broken]")
	} else if l {
		fmt.Printf("%s -> %s\n", path+filename, link)
	}
}

func fCase(f bool, path string, filename string, extension string) {
	if f && strings.HasSuffix(filename, extension) {
		fmt.Println(path + filename)
	}
}

func findAll(path string, f, d, l bool, extension string) {
	if !strings.HasSuffix(path, "/") {
		path = path + "/"
	}
	files, err := os.ReadDir(path)
	err_code(err)
	for _, file := range files {
		if file.IsDir() {
			dCase(d, path, file.Name())
			findAll(path+file.Name(), f, d, l, extension)
		} else {
			link, err := os.Readlink(path + file.Name())
			if err == nil {
				lCase(l, path, file.Name(), link)
			} else {
				fCase(f, path, file.Name(), extension)
			}
		}
	}
}

func main() {
	filesPtr := flag.Bool("f", false, "files")
	dirsPtr := flag.Bool("d", false, "directories")
	linksPtr := flag.Bool("sl", false, "symbol links")
	extPtr := flag.String("ext", "", "file extensions")
	flag.Parse()
	errorFlagsCase(*filesPtr, *extPtr)
	noFlagsCase(filesPtr, dirsPtr, linksPtr)
	findAll(os.Args[len(os.Args)-1], *filesPtr, *dirsPtr, *linksPtr, *extPtr)
}
