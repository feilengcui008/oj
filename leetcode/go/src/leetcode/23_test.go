package leetcode

import (
	"testing"
)

func Test_23(t *testing.T) {
	data := []*ListNode{
		&ListNode{Val: 0, Next: &ListNode{Val: 1, Next: nil}},
		&ListNode{Val: 2, Next: &ListNode{Val: 3, Next: nil}},
		&ListNode{Val: 4, Next: &ListNode{Val: 5, Next: nil}},
		nil,
		nil,
	}
	target := &ListNode{0, nil}
	//var target *ListNode = nil
	root := target
	for i := 1; i <= 5; i++ {
		target.Next = &ListNode{Val: i, Next: nil}
		target = target.Next
	}
	res := mergeKLists(data)
	for root != nil && res != nil {
		if root.Val != res.Val {
			t.Errorf("number 23 failed\n")
		}
		root = root.Next
		res = res.Next
	}
	if root != nil || res != nil {
		t.Errorf("number 23 failed\n")
	}
}
