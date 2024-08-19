package tree

import (
	"fmt"
	"math"
	"os"
)

type TreeNode struct {
	HasToy bool
	Left   *TreeNode
	Right  *TreeNode
}

func PrintTree(node *TreeNode, ns int, ch rune) {
	if node == nil {
		return
	}

	for i := 0; i < ns; i++ {
		fmt.Fprint(os.Stdout, " ")
	}
	var val uint8
	if node.HasToy {
		val = 1
	}
	fmt.Fprintf(os.Stdout, "%c: %d\n", ch, val)
	PrintTree(node.Left, ns+2, 'L')
	PrintTree(node.Right, ns+2, 'R')
}

func AreToysBalanced(root *TreeNode) bool {
	var l, r int
	CountToys(root.Left, &l)
	CountToys(root.Right, &r)

	return l == r
}

func CountToys(root *TreeNode, count *int) {
	if root == nil {
		return
	}
	if root.HasToy {
		*count++
	}
	CountToys(root.Left, count)
	CountToys(root.Right, count)
}

func CreateTreeFromArray(arr []uint8) *TreeNode {
	// 0 = no toy
	// 1 = has toy
	// 2 = nil node
	if len(arr) == 0 {
		return nil
	}

	nodes := make([]*TreeNode, len(arr))
	for i, val := range arr {
		if val != 2 {
			nodes[i] = &TreeNode{HasToy: val == 1}
		}
	}

	for i := 0; i < len(arr)/2; i++ {
		if nodes[i] != nil {
			if 2*i+1 < len(arr) {
				nodes[i].Left = nodes[2*i+1]
			}
			if 2*i+2 < len(arr) {
				nodes[i].Right = nodes[2*i+2]
			}
		}
	}

	return nodes[0]
}

type QuNode struct {
	node *TreeNode
	next *QuNode
}

type Queue struct {
	front, back *QuNode
	len         uint
}

func newQueue() *Queue {
	return &Queue{}
}

func (q *Queue) push(treeNode *TreeNode) {
	n := &QuNode{}
	n.node = treeNode
	if q.front == nil {
		q.front = n
		q.back = n
		q.len = 1
	} else {
		q.back.next = n
		q.back = n
		q.len++
	}
}

func (q *Queue) pop() *TreeNode {
	res := q.front.node
	q.front = q.front.next
	q.len--
	if q.front == nil {
		q.back = nil
	}
	return res
}

func UnrollGarland(root *TreeNode) []bool {
	if root == nil {
		return nil
	}
	res := make([]bool, 0, 1)
	queue := newQueue()
	queue.push(root)
	level := 0
	levelSize := 1
	l := make([]bool, 0, levelSize)
	for queue.len != 0 {
		for i := 0; i < levelSize && queue.len != 0; i++ {

			curr := queue.pop()

			if curr.Left != nil {
				queue.push(curr.Left)
			}
			if curr.Right != nil {
				queue.push(curr.Right)
			}
			l = append(l, curr.HasToy)
		}
		if level%2 == 0 {
			reverseSlice(l)
		}
		res = append(res, l...)
		l = l[:0]
		level++
		levelSize = int(math.Pow(2, float64(level)))
	}
	return res
}

func reverseSlice(arr []bool) {
	start, end := 0, len(arr)-1
	for start < end {
		arr[start], arr[end] = arr[end], arr[start]
		start++
		end--
	}
}
