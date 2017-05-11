package leetcode

// time: O(nlogn), space: O(n)
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	var (
		i     int
		left  *TreeNode
		right *TreeNode
	)
	for i = 0; i < len(inorder); i++ {
		if inorder[i] == preorder[0] {
			break
		}
	}
	if i == 0 {
		left = nil
		right = buildTree(preorder[1:], inorder[i+1:])
	} else {
		left = buildTree(preorder[1:i+1], inorder[0:i])
		right = buildTree(preorder[i+1:], inorder[i+1:])
	}
	root := &TreeNode{Val: preorder[0], Left: left, Right: right}
	return root
}
