package leetcode

import (
	"sort"
	"testing"
)

// 1
func Test_1(t *testing.T) {
	arr := []int{2, 7, 11, 15}
	target := 9
	res := twoSum(arr, target)
	real := []int{0, 1}
	sort.Ints(res)
	if len(res) != len(real) {
		t.Errorf("number 1 failed: %v != %v", arr, real)
	}
	for i := 0; i < len(res); i++ {
		if res[i] != real[i] {
			t.Fatalf("number 1 failed: %v != %v", arr, real)
		}
	}
}

// 2
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

// 3
func Test_3(t *testing.T) {
	var data = []string{
		"abcabcbb",
		"bbbbb",
		"pwwkew",
	}
	var target = []int{3, 1, 3}
	n := len(data)
	for i := 0; i < n; i++ {
		if lengthOfLongestSubstring(data[i]) != target[i] {
			t.Errorf("number 3 failed: %v %v", data[i], target[i])
		}
	}
}

// 4
func Test_4(t *testing.T) {
	nums1 := [][]int{
		[]int{1, 3},
		[]int{1, 2},
		[]int{1, 1},
	}
	nums2 := [][]int{
		[]int{2},
		[]int{3, 4},
		[]int{1, 2},
	}
	target := []float64{2.0, 2.5, 1.0}
	size := len(nums1)
	for i := 0; i < size; i++ {
		if findMedianSortedArrays(nums1[i], nums2[i]) != target[i] {
			t.Errorf("number 4 failed")
		}
	}
}

// 5
func Test_5(t *testing.T) {
	data := []string{"babad", "cbbd", "abcda", "ccd", "ccc"}
	target := [][]string{
		[]string{"bab", "aba"},
		[]string{"bb"},
		[]string{"a"},
		[]string{"cc"},
		[]string{"ccc"},
	}
	size := len(data)
	for i := 0; i < size; i++ {
		r := longestPalindrome(data[i])
		var j int
		for j = 0; j < len(target[i]); j++ {
			if target[i][j] == r {
				break
			}
		}
		if j == len(target[i]) {
			t.Errorf("number 5 failed")
		}
	}
}

// 11
func Test_11(t *testing.T) {
	data := [][]int{
		[]int{2, 3, 2, 4},
	}
	target := []int{6}
	size := len(data)
	for i := 0; i < size; i++ {
		if maxArea(data[i]) != target[i] {
			t.Errorf("number 11 failed")
		}
	}
}

// 14
func Test_14(t *testing.T) {
	data := [][]string{
		[]string{"pre", "prefix"},
		[]string{"q", "p"},
	}
	target := []string{"pre", ""}
	size := len(data)
	for i := 0; i < size; i++ {
		if longestCommonPrefix(data[i]) != target[i] {
			t.Errorf("number 14 failed: %v", target[i])
		}
	}
}

// 20
func Test_20(t *testing.T) {
	data := []string{
		"()[]",
		"(]",
		"]",
	}
	target := []bool{true, false, false}
	size := len(data)
	for i := 0; i < size; i++ {
		if isValid(data[i]) != target[i] {
			t.Errorf("number 20 failed\n")
		}
	}
}

// 21
func Test_21(t *testing.T) {
	// just see Test_23
}

// 23
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

// 33
func Test_33(t *testing.T) {
	data := [][]int{
		[]int{4, 5, 6, 7, 0, 1, 2},
		[]int{4, 5, 1, 2, 3},
		[]int{1, 2, 3, 4},
		[]int{},
	}
	target := []int{0, 5, 3, 0}
	result := []int{4, 1, 2, -1}
	size := len(data)
	for i := 0; i < size; i++ {
		if m := search(data[i], target[i]); m != result[i] {
			t.Errorf("number 33 failed: %v", m)
		}
	}
}
