package leetcode

import (
	"testing"
)

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
