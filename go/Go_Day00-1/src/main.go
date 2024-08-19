package main

import (
	"fmt"
	"log"
	"math"
	"os"
	"sort"
)

func input() []int {
	var slice []int
	var box int = 0
	for {
		_, err := fmt.Scanf("%d ", &box)
		if err != nil {
			if err.Error() == `EOF` {
				break
			}
			log.Fatalf("Wrong input\n")
		}
		if -100000 < box && box < 100000 {
			slice = append(slice, box)
		} else {
			log.Fatalf("Out of range\n")
		}
	}
	if len(slice) == 0 {
		log.Fatalf("input data is empty\n")
	}
	return slice
}

func mean(slice []int) float64 {
	var summ float64
	for _, el := range slice {
		summ += float64(el)
	}
	return summ / float64(len(slice))
}

func median(slice []int) (result float64) {
	sort_slice := slice
	sort.Ints(sort_slice)
	if len(sort_slice)%2 == 1 {
		result = float64(sort_slice[len(sort_slice)/2])
	} else {
		result = float64(sort_slice[len(sort_slice)/2-1]+sort_slice[len(sort_slice)/2]) / 2
	}
	return
}

func mode(slice []int) (max_el int) {
	m := make(map[int]int)
	for _, el := range slice {
		m[el] += 1
		if m[el] > m[max_el] || (m[el] == m[max_el] && el < max_el) {
			max_el = el
		}
	}
	return
}

func SD(slice []int) float64 {
	var result float64
	if len(slice) >= 2 {
		for _, el := range slice {
			result += math.Pow(float64(el)-mean(slice), 2)
		}
		result /= float64(len(slice))
	}
	return math.Sqrt(result)

}

func main() {
	var slice = input()
	if len(os.Args) == 1 {
		fmt.Printf("Mean: %.1f\n", mean(slice))
		fmt.Printf("Median: %.1f\n", median(slice))
		fmt.Printf("Mode: %d\n", mode(slice))
		fmt.Printf("SD: %.2f\n", SD(slice))
	}
	for i := 1; i < len(os.Args); i++ {
		if os.Args[i] == "mean" {
			fmt.Printf("Mean: %.1f\n", mean(slice))
		} else if os.Args[i] == "median" {
			fmt.Printf("Median: %.1f\n", median(slice))
		} else if os.Args[i] == "mode" {
			fmt.Printf("Mode: %d\n", mode(slice))
		} else if os.Args[i] == "sd" {
			fmt.Printf("SD: %.2f\n", SD(slice))
		}
	}
}
