package leetcode

import (
	"testing"
)

func Test_109(t *testing.T) {
	data := [][]int{
		[]int{1, 2, 3, 4, 5},
	}
	root := &ListNode{}
	tp := root
	for i := 0; i < len(data); i++ {
		for j := 0; j < len(data[i]); j++ {
			tp.Next = &ListNode{Val: data[i][j]}
			tp = tp.Next
		}
		res := sortedListToBST(root.Next)
		if !IsBalanced(res) {
			t.Fail()
		}
		var d []int
		InOrder(res, &d)
		for k := 0; k < len(d); k++ {
			if data[i][k] != d[k] {
				t.Fail()
			}
		}
	}
}
