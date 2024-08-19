package mincoins

import (
	"fmt"
	"os"
	"sort"
	"testing"
	"time"
)

type coinsTest struct {
	value             int
	coins, exp_output []int
}

type testCaseAttrs struct {
	number           int
	result1, result2 time.Duration
}

var testCases = []coinsTest{
	{
		value:      13,
		coins:      []int{1, 5, 10},
		exp_output: []int{10, 1, 1, 1},
	},
	{
		value:      13,
		coins:      []int{1, 1, 5, 5, 10, 10},
		exp_output: []int{10, 1, 1, 1},
	},
	{
		value:      0,
		coins:      []int{1, 5, 10},
		exp_output: []int{},
	},
	{
		value:      18,
		coins:      []int{1, 3, 7},
		exp_output: []int{7, 7, 3, 1},
	},
	{
		value:      13,
		coins:      []int{10, 5, 1},
		exp_output: []int{10, 1, 1, 1},
	},
	{
		value:      13,
		coins:      []int{10, 5, 1, 1},
		exp_output: []int{10, 1, 1, 1},
	},
	{
		value:      32,
		coins:      []int{10, 5, 1, 1},
		exp_output: []int{10, 10, 10, 1, 1},
	},
}

func Test_best_time(t *testing.T) {
	var times []testCaseAttrs
	for i, testCase := range testCases {
		start := time.Now()
		minCoins2(testCase.value, testCase.coins)
		times = append(times, testCaseAttrs{number: i, result1: time.Duration(time.Since(start).Nanoseconds())})
	}
	sort.Slice(times, func(i, j int) bool {
		return times[i].result1 > times[j].result1
	})
	file, err := os.Create("top10.txt")
	if err != nil {
		t.Fatalf("Error creating a file: %s", err.Error())
	}
	defer file.Close()
	for _, testTime := range times {
		fmt.Fprintf(file, "Test case number %d finished with %d ㎲\n", testTime.number, testTime.result1)
	}
}

func Test_times_compare_func(t *testing.T) {
	var times []testCaseAttrs
	for i, testCase := range testCases {
		start := time.Now()
		minCoins2(testCase.value, testCase.coins)
		res1Time := time.Duration(time.Since(start).Nanoseconds())
		start = time.Now()
		minCoins(testCase.value, testCase.coins)
		res2Time := time.Duration(time.Since(start).Nanoseconds())
		times = append(times, testCaseAttrs{number: i, result1: res1Time, result2: res2Time})
	}
	sort.Slice(times, func(i, j int) bool {
		return times[i].result1 > times[j].result1
	})
	file, err := os.Create("compare_times.txt")
	if err != nil {
		t.Fatalf("Error creating a file: %s", err.Error())
	}
	defer file.Close()
	for i, testTime := range times {
		fmt.Fprintf(file, "Test case number %d minCoins2 finished with %d ㎲, minCoins with %d ㎲. The difference is: %d\n", testTime.number, testTime.result1, testTime.result2, testTime.result1-testTime.result2)
		if i == 10 {
			break
		}
	}
}
