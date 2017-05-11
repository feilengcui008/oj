package leetcode

import (
	"testing"
)

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
