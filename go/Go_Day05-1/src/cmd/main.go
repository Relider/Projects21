package main

import (
	"fmt"
	p "sobchakr/day05/present"
	t "sobchakr/day05/trees"
)

func main() {
	// EX00: balanced tree
	fmt.Println("----------------------")
	fmt.Println("EX00: Balanced trees")
	var count int
	bal := &t.TreeNode{HasToy: true}
	bal.Left = &t.TreeNode{HasToy: true}
	bal.Left.Left = &t.TreeNode{HasToy: true}
	bal.Right = &t.TreeNode{HasToy: true}
	bal.Right.Right = &t.TreeNode{HasToy: true}
	t.PrintTree(bal, 0, 'M')
	t.CountToys(bal, &count)
	fmt.Println("The tree has", count, "toys")
	fmt.Println("Is tree balanced?", t.AreToysBalanced(bal))

	fmt.Println()
	imbal := &t.TreeNode{HasToy: true}
	imbal.Left = &t.TreeNode{HasToy: true}
	imbal.Left.Left = &t.TreeNode{HasToy: true}
	imbal.Right = &t.TreeNode{HasToy: true}
	imbal.Right.Right = &t.TreeNode{HasToy: false}
	t.PrintTree(imbal, 0, 'M')
	count = 0
	t.CountToys(imbal, &count)
	fmt.Println("The tree has", count, "toys")
	fmt.Println("Is tree balanced?", t.AreToysBalanced(imbal))

	arr := []uint8{0, 1, 0, 2, 1, 2, 1}
	bt := t.CreateTreeFromArray(arr)
	fmt.Println()
	t.PrintTree(bt, 0, 'M')
	count = 0
	t.CountToys(bt, &count)
	fmt.Println("The tree has", count, "toys")
	fmt.Println("Is tree balanced?", t.AreToysBalanced(bt))
	fmt.Println()

	// EX01: unroll garland
	fmt.Println("----------------------")
	fmt.Println("EX01: Unroll garland")
	arr1 := []uint8{1, 1, 0, 1, 0, 1, 1}
	tree := t.CreateTreeFromArray(arr1)
	res := t.UnrollGarland(tree)
	for _, val := range res {
		fmt.Print(val, " ")
	}
	fmt.Println()
	fmt.Println()

	// EX02 Presents Heap
	fmt.Println("----------------------")
	fmt.Println("EX02: Heap of Presents")
	s := []p.Present{
		{Value: 2, Size: 2},
		{Value: 5, Size: 1},
		{Value: 5, Size: 2},
		{Value: 1, Size: 1},
	}
	fmt.Println("Available presents")
	for _, el := range s {
		fmt.Printf("(%d, %d)\n", el.Value, el.Size)
	}

	res1, _ := p.GetNCoolestPresents(s, 2)
	fmt.Println("Two coolest presents")
	for _, el := range res1 {
		fmt.Printf("(%d, %d)\n", el.Value, el.Size)
	}
	fmt.Println()

	// EX03 Knapsack
	fmt.Println("----------------------")
	fmt.Println("EX03: Knapsack")
	presents := []p.Present{
		{Value: 10, Size: 1},
		{Value: 9, Size: 5},
		{Value: 8, Size: 2},
		{Value: 7, Size: 3},
		{Value: 6, Size: 4},
	}
	fmt.Println("Available presents")
	for _, el := range presents {
		fmt.Printf("(%d, %d)\n", el.Value, el.Size)
	}
	res2 := p.GrabPresents(presents, 5)
	fmt.Println("Got presents with capacity 5")
	for _, el := range res2 {
		fmt.Printf("(%d, %d)\n", el.Value, el.Size)
	}

}
