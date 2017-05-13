package leetcode

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if root.Left == nil {
		return minDepth(root.Right) + 1
	}
	if root.Right == nil {
		return minDepth(root.Left) + 1
	}
	l := minDepth(root.Left)
	r := minDepth(root.Right)
	if l < r {
		return l + 1
	}
	return r + 1
}
