package leetcode

import (
	"testing"
)

func Test_107(t *testing.T) {
	root := &TreeNode{Val: 3}
	root.Left = &TreeNode{Val: 9}
	root.Right = &TreeNode{Val: 20}
	root.Right.Left = &TreeNode{Val: 15}
	root.Right.Right = &TreeNode{Val: 7}
	res := levelOrderBottom(root)
	data := [][]int{
		[]int{15, 7},
		[]int{9, 20},
		[]int{3},
	}
	for i := 0; i < len(data); i++ {
		for j := 0; j < len(data[i]); j++ {
			if data[i][j] != res[i][j] {
				t.Fail()
			}
		}
	}
}
