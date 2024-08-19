package main

import (
	"fmt"
	"os"
	"sobchakr/day06/logoprint"
)

const (
	FILENAME string = "logo.png"
)

func main() {
	err := logoprint.CreateLogo(FILENAME)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error during image creation: %s\n", err.Error())
		os.Exit(1)
	}
}
