package leetcode

import (
	"testing"
)

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
