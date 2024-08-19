package presents

import (
	"testing"
)

func TestGetNCoolestPresents(t *testing.T) {
	tests := []struct {
		presents []Present
		n        int
		expected []Present
	}{
		{
			presents: []Present{
				{Value: 10, Size: 1},
				{Value: 10, Size: 2},
				{Value: 8, Size: 1},
				{Value: 15, Size: 3},
			},
			n: 2,
			expected: []Present{
				{Value: 15, Size: 3},
				{Value: 10, Size: 1},
			},
		},
		{
			presents: []Present{
				{Value: 5, Size: 2},
				{Value: 7, Size: 3},
				{Value: 5, Size: 1},
			},
			n: 3,
			expected: []Present{
				{Value: 7, Size: 3},
				{Value: 5, Size: 1},
				{Value: 5, Size: 2},
			},
		},
		{
			presents: []Present{
				{Value: 1, Size: 1},
			},
			n: 1,
			expected: []Present{
				{Value: 1, Size: 1},
			},
		},
	}

	for _, tt := range tests {
		actual, err := GetNCoolestPresents(tt.presents, tt.n)
		if err != nil {
			t.Errorf("got error: %v, want nil", err)
			continue
		}

		if len(actual) != len(tt.expected) {
			t.Errorf("got %v, want %v", actual, tt.expected)
			continue
		}

		for i := range actual {
			if actual[i] != tt.expected[i] {
				t.Errorf("got %v, want %v", actual, tt.expected)
				break
			}
		}
	}
}

func TestGetNCoolestPresentsInvalidN(t *testing.T) {
	_, err := GetNCoolestPresents([]Present{{Value: 1, Size: 1}}, 2)
	if err == nil {
		t.Error("expected error, got nil")
	}

	_, err = GetNCoolestPresents([]Present{{Value: 1, Size: 1}}, -1)
	if err == nil {
		t.Error("expected error, got nil")
	}
}

func TestGrabPresents(t *testing.T) {
	tests := []struct {
		presents []Present
		capacity uint
		expected []Present
	}{
		{
			presents: []Present{
				{Value: 10, Size: 1},
				{Value: 5, Size: 2},
				{Value: 8, Size: 1},
				{Value: 15, Size: 3},
			},
			capacity: 4,
			expected: []Present{
				{Value: 15, Size: 3},
				{Value: 10, Size: 1},
			},
		},
		{
			presents: []Present{
				{Value: 5, Size: 2},
				{Value: 7, Size: 3},
				{Value: 5, Size: 1},
			},
			capacity: 3,
			expected: []Present{
				{Value: 7, Size: 3},
			},
		},
		{
			presents: []Present{
				{Value: 1, Size: 1},
			},
			capacity: 1,
			expected: []Present{
				{Value: 1, Size: 1},
			},
		},
		{
			presents: []Present{
				{Value: 10, Size: 1},
				{Value: 9, Size: 2},
				{Value: 8, Size: 2},
				{Value: 7, Size: 3},
				{Value: 6, Size: 4},
			},
			capacity: 5,
			expected: []Present{
				{Value: 10, Size: 1},
				{Value: 9, Size: 2},
				{Value: 8, Size: 2},
			},
		},
		{
			presents: []Present{
				{Value: 10, Size: 1},
				{Value: 9, Size: 5},
				{Value: 8, Size: 2},
				{Value: 7, Size: 3},
				{Value: 6, Size: 4},
			},
			capacity: 5,
			expected: []Present{
				{Value: 10, Size: 1},
				{Value: 8, Size: 2},
			},
		},
	}

	for _, tt := range tests {
		actual := GrabPresents(tt.presents, tt.capacity)
		if len(actual) != len(tt.expected) {
			t.Errorf("got %v, want %v", actual, tt.expected)
			continue
		}
		for i := range actual {
			if actual[i] != tt.expected[i] {
				t.Errorf("got %v, want %v", actual, tt.expected)
				break
			}
		}
	}
}

func TestGrabPresentsZeroCapacity(t *testing.T) {
	presents := []Present{
		{Value: 10, Size: 1},
		{Value: 5, Size: 2},
	}

	actual := GrabPresents(presents, 0)
	if len(actual) != 0 {
		t.Errorf("expected no presents, got %v", actual)
	}
}

func TestGrabPresentsExceedsCapacity(t *testing.T) {
	presents := []Present{
		{Value: 10, Size: 5},	
		{Value: 20, Size: 10},
	}

	actual := GrabPresents(presents, 1)
	if len(actual) != 0 {
		t.Errorf("expected no presents, got %v", actual)
	}
}
