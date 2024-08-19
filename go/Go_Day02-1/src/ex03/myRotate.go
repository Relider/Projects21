package main

import (
	"archive/tar"
	"compress/gzip"
	"flag"
	"io"
	"log"
	"os"
	"strconv"
	"strings"
	"sync"
)

var wg sync.WaitGroup

func argParser(dirPtr string) int {
	result := 3
	if dirPtr == "" {
		result = 1
	}
	return result
}

func err_test(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func archive(file string, dir string) {
	defer wg.Done()
	info, err := os.Stat(file)
	err_test(err)
	if !strings.HasSuffix(file, ".log") {
		log.Fatal(file + ": it's not a log file")
	}

	var tarName string
	if dir == "" {
		tarName = strings.TrimSuffix(file, ".log")
	} else {
		tarName = dir + strings.TrimSuffix(info.Name(), ".log")
	}
	tarName = tarName + strconv.FormatInt(info.ModTime().Unix(), 10) + ".tar.gz"

	tarFile, err := os.Create(tarName)
	err_test(err)
	defer tarFile.Close()

	gzipw := gzip.NewWriter(tarFile)
	defer gzipw.Close()
	tarw := tar.NewWriter(gzipw)
	defer tarw.Close()

	ffile, err := os.Open(file)
	err_test(err)
	defer ffile.Close()

	header, err := tar.FileInfoHeader(info, info.Name())
	header.Name = file
	err_test(err)

	err = tarw.WriteHeader(header)
	err_test(err)
	_, err = io.Copy(tarw, ffile)
	err_test(err)
}

func archiveAll(files []string, dir string) {
	if dir != "" {
		if !strings.HasSuffix(dir, "/") {
			dir = dir + "/"
		}
		dir = strings.TrimPrefix(dir, "/")
		_, err := os.Stat(dir)
		if err != nil {
			if err := os.MkdirAll(dir, os.ModePerm); err != nil {
				log.Fatal(err)
			}
		}
	}

	wg.Add(len(files))
	for _, file := range files {
		go archive(file, dir)
	}
	wg.Wait()
}

func main() {
	dirPtr := flag.String("a", "", "directory for archived files")
	flag.Parse()

	argPoint := argParser(*dirPtr)
	archiveAll(os.Args[argPoint:], *dirPtr)
}
