package tree

import (
	"testing"
)

func TestCountToys(t *testing.T) {
	tests := []struct {
		arr      []uint8
		expected int
	}{
		{[]uint8{0, 1, 0, 2, 1, 2, 1}, 3},
		{[]uint8{1, 1, 1, 1, 1, 1, 1}, 7},
		{[]uint8{0, 0, 0, 0, 0, 0, 0}, 0},
		{[]uint8{1, 2, 2, 2, 2, 2, 2}, 1},
		{[]uint8{2, 2, 2, 2, 2, 2, 2}, 0},
	}

	for _, test := range tests {
		root := CreateTreeFromArray(test.arr)
		var count int
		CountToys(root, &count)
		if count != test.expected {
			t.Errorf("For tree %v, expected %d toys, but got %d", test.arr, test.expected, count)
		}
	}
}

func TestAreToysBalanced(t *testing.T) {
	tests := []struct {
		arr      []uint8
		expected bool
	}{
		{[]uint8{0}, true},
		{[]uint8{1, 1, 1, 1, 1, 1, 1}, true},
		{[]uint8{0, 0, 0, 0, 0, 0, 0}, true},
		{[]uint8{1, 2, 2, 2, 2, 2, 2}, true},
		{[]uint8{1, 1, 1, 2, 2, 2, 2}, true},
		{[]uint8{0, 0, 1, 0, 1, 2, 2}, true},
		{[]uint8{1, 1, 0, 1, 0, 1, 1}, true},
		{[]uint8{1, 1, 0}, false},
		{[]uint8{0, 1, 0, 2, 1, 2, 1}, false},
	}

	for _, test := range tests {
		root := CreateTreeFromArray(test.arr)
		result := AreToysBalanced(root)
		if result != test.expected {
			t.Errorf("For tree %v, expected balanced to be %v, but got %v", test.arr, test.expected, result)
		}
	}
}

func areEqual(a, b []bool) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func TestUnrollGarland(t *testing.T) {
	arr := []uint8{1}
	tree := CreateTreeFromArray(arr)
	res := UnrollGarland(tree)
	expected := []bool{true}

	if !areEqual(res, expected) {
		t.Errorf("Test UnrollGarland failed\nExpected: %v\nGot:      %v", expected, res)
	}
}
