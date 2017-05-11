package leetcode

import (
	"testing"
)

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
