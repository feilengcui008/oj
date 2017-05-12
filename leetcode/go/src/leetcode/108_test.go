package leetcode

import (
	"testing"
)

func Test_108(t *testing.T) {
	data := [][]int{
		[]int{1, 2, 3, 4, 5},
	}
	for i := 0; i < len(data); i++ {
		root := sortedArrayToBST(data[i])
		if !IsBalanced(root) {
			t.Fail()
		}
		var temp []int
		InOrder(root, &temp)
		for j := 0; j < len(temp); j++ {
			if temp[j] != data[i][j] {
				t.Fail()
			}
		}
	}
}
