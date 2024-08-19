package mincoins

import (
	"testing"
)

type coinsTest struct {
	value             int
	coins, exp_output []int
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
		coins:      []int{2, 5, 10},
		exp_output: []int{},
	},
	{
		value:      13,
		coins:      []int{10, 5, 1},
		exp_output: []int{10, 1, 1, 1},
	},
	{
		value:      13,
		coins:      []int{},
		exp_output: []int{},
	},
	{
		value:      13,
		coins:      []int{-10, 5, 1},
		exp_output: []int{},
	},
	{
		value:      13,
		coins:      []int{10, 5, 1, 1},
		exp_output: []int{10, 1, 1, 1},
	},
}

func cmprSlices(ar1, ar2 []int) bool {
	if len(ar1) != len(ar2) {
		return false
	}
	for i, val := range ar1 {
		if val != ar2[i] {
			return false
		}
	}
	return true
}

func Test_old_func(t *testing.T) {
	for _, testCase := range testCases {
		result := minCoins(testCase.value, testCase.coins)
		if !cmprSlices(result, testCase.exp_output) {
			t.Fatalf("Expected: %v\ngot: %v\n", testCase.exp_output, result)
		}
	}
}

func Test_new_func(t *testing.T) {
	for _, testCase := range testCases {
		result := minCoins2(testCase.value, testCase.coins)
		if !cmprSlices(result, testCase.exp_output) {
			t.Fatalf("Expected: %v\ngot: %v\n", testCase.exp_output, result)
		}
	}
}
