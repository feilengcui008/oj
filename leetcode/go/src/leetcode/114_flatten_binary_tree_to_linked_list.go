package leetcode

// flatten a inner TreeNode and return tail
func innerFlatten(root *TreeNode) *TreeNode {
	if root == nil || (root.Left == nil && root.Right == nil) {
		return root
	}
	l, r := root.Left, root.Right
	var ret *TreeNode
	if l != nil {
		lt := innerFlatten(l)
		ret = lt
		root.Right = l
		root.Left = nil
		lt.Right = r
	}
	if r != nil {
		rt := innerFlatten(r)
		ret = rt
	}
	return ret
}

func flatten(root *TreeNode) {
	innerFlatten(root)
}
