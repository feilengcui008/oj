package leetcode

import (
	"testing"
)

func Test_2(t *testing.T) {
	first := [][]int{
		[]int{2, 4, 3},
		[]int{9, 9},
	}
	second := [][]int{
		[]int{5, 6, 4},
		[]int{9},
	}
	target := [][]int{
		[]int{7, 0, 8},
		[]int{8, 0, 1},
	}
	size := len(first)
	for i := 0; i < size; i++ {
		t.Logf("round: %v\n", i)
		len1 := len(first[i])
		len2 := len(second[i])
		len3 := len(target[i])
		// l1
		var temp *ListNode = nil
		for j := len1 - 1; j >= 0; j-- {
			temp = &ListNode{first[i][j], temp}
		}
		l1 := temp
		// l2
		temp = nil
		for j := len2 - 1; j >= 0; j-- {
			temp = &ListNode{second[i][j], temp}
		}
		l2 := temp
		// l3
		temp = nil
		for j := len3 - 1; j >= 0; j-- {
			temp = &ListNode{target[i][j], temp}
		}
		l3 := temp
		newRoot := addTwoNumbers(l1, l2)
		if newRoot == nil {
			t.Errorf("number 2 failed")
		}
		for newRoot != nil && l3 != nil {
			t.Log(newRoot.Val)
			if newRoot.Val != l3.Val {
				t.Errorf("number 2 failed")
			}
			newRoot = newRoot.Next
			l3 = l3.Next
		}
		if newRoot != nil || l3 != nil {
			t.Errorf("number 2 failed")
		}

	}
}
