package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"os/exec"
)

func errorFlagsCase() {
	if len(os.Args) < 2 {
		log.Fatal("Invalid number of arguments")
	}
}

func main() {
	errorFlagsCase()
	var args []string

	args = append(args, os.Args[2:]...)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
	for scanner.Scan() {
		args = append(args, scanner.Text())
	}

	cmd := exec.Command(os.Args[1], args...)
	stdout, err := cmd.CombinedOutput()
	if err != nil && err.Error() == "exit status 1" {
		print(string(stdout))
		os.Exit(1)
	}
	fmt.Print(string(stdout))
}
