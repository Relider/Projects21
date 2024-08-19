package presents

import (
	"container/heap"
	"fmt"
)

type Present struct {
	Value int
	Size  int
}

type PresentHeap []Present

func (h PresentHeap) Len() int { return len(h) }
func (h PresentHeap) Less(i, j int) bool {
	if h[i].Value == h[j].Value {
		return h[i].Size < h[j].Size
	}
	return h[i].Value > h[j].Value
}
func (h PresentHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}
func (h *PresentHeap) Push(x any) {
	*h = append(*h, x.(Present))
}
func (h *PresentHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func sliceToHeap(s []Present) *PresentHeap {
	h := &PresentHeap{}
	for _, el := range s {
		heap.Push(h, el)
	}
	heap.Init(h)
	return h
}

func GetNCoolestPresents(pres []Present, n int) ([]Present, error) {
	if n < 1 || n > len(pres) {
		return nil, fmt.Errorf("Invalid n parameter")
	}
	h := sliceToHeap(pres)
	res := make([]Present, n)
	for i := 0; i < n; i++ {
		res[i] = heap.Pop(h).(Present)
	}
	return res, nil
}

func GrabPresents(pres []Present, s uint) []Present {
	h := sliceToHeap(pres)
	res := make([]Present, 0, 1)
	var weight uint = 0
	for weight < s && h.Len() > 0 {
		pr := heap.Pop(h).(Present)
		if weight+uint(pr.Size) <= s {
			res = append(res, pr)
			weight += uint(pr.Size)
		}
	}
	return res
}
