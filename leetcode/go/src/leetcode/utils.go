package leetcode

import (
	"errors"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func PreOrder(root *TreeNode, res *[]int) {
	if root == nil {
		return
	}
	*res = append(*res, root.Val)
	PreOrder(root.Left, res)
	PreOrder(root.Right, res)
}

func InOrder(root *TreeNode, res *[]int) {
	if root == nil {
		return
	}
	InOrder(root.Left, res)
	*res = append(*res, root.Val)
	InOrder(root.Right, res)
}

func PostOrder(root *TreeNode, res *[]int) {
	if root == nil {
		return
	}
	PostOrder(root.Left, res)
	PostOrder(root.Right, res)
	*res = append(*res, root.Val)
}

func GetHeight(root *TreeNode) int {
	if root == nil {
		return 0
	}
	l := GetHeight(root.Left)
	r := GetHeight(root.Right)
	if l > r {
		return l + 1
	}
	return r + 1
}

func IsBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	l := GetHeight(root.Left)
	r := GetHeight(root.Right)
	return IsBalanced(root.Left) && IsBalanced(root.Right) && (l == r || l == r+1 || l == r-1)
}

type Queue interface {
	Push(interface{})
	Pop() error
	Front() (interface{}, error)
	Back() (interface{}, error)
	Empty() bool
	Size() int
}

// no generics kind of sucks...
type SimpleQueue []interface{}

func (q *SimpleQueue) Push(e interface{}) {
	*q = append(*q, e)
}

func (q *SimpleQueue) Pop() error {
	if len(*q) == 0 {
		return errors.New("queue is empty")
	}
	*q = (*q)[1:]
	return nil
}

func (q *SimpleQueue) Front() (interface{}, error) {
	if len(*q) == 0 {
		return nil, errors.New("queue is empty")
	}
	return (*q)[0], nil
}

func (q *SimpleQueue) Back() (interface{}, error) {
	if len(*q) == 0 {
		return nil, errors.New("queue is empty")
	}
	return (*q)[len(*q)], nil
}

func (q *SimpleQueue) Empty() bool {
	return len(*q) == 0
}

func (q *SimpleQueue) Size() int {
	return len(*q)
}
