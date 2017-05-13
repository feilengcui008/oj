package leetcode

func getHeight(root *TreeNode) int {
	if root == nil {
		return 0
	}
	l := getHeight(root.Left)
	r := getHeight(root.Right)
	if l > r {
		return l + 1
	}
	return r + 1
}

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	l := getHeight(root.Left)
	r := getHeight(root.Right)
	return isBalanced(root.Left) && isBalanced(root.Right) && (l == r || l == r+1 || l == r-1)
}
