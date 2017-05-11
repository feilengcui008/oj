package leetcode

import (
	"testing"
)

func PreOrder(root *TreeNode, res *[]int) {
	if root == nil {
		return
	}
	*res = append(*res, root.Val)
	PreOrder(root.Left, res)
	PreOrder(root.Right, res)
}

func InOrder(root *TreeNode, res *[]int) {
	if root == nil {
		return
	}
	InOrder(root.Left, res)
	*res = append(*res, root.Val)
	InOrder(root.Right, res)
}

// 105
func Test_105(t *testing.T) {
	preorderdata := [][]int{
		[]int{-1},
		[]int{1, 2, 3},
		[]int{1, 2, 3, 4},
	}
	inorderdata := [][]int{
		[]int{-1},
		[]int{2, 1, 3},
		[]int{3, 2, 4, 1},
	}
	for i := 0; i < len(preorderdata); i++ {
		root := buildTree(preorderdata[i], inorderdata[i])
		t.Logf("%d\n", root.Val)
		var (
			pre = []int{}
			in  = []int{}
		)
		PreOrder(root, &pre)
		InOrder(root, &in)
		t.Logf("pre: %v, in: %v\n", pre, in)
		if len(pre) != len(preorderdata[i]) || len(in) != len(inorderdata[i]) {
			t.Fail()
		}
		for j := 0; j < len(pre); j++ {
			if pre[j] != preorderdata[i][j] || in[j] != inorderdata[i][j] {
				t.Fail()
			}
		}
	}
}
