package leetcode

// time: O(nlogn), space: O(n)
func buildTree1(inorder []int, postorder []int) *TreeNode {
	if len(postorder) == 0 {
		return nil
	}
	var (
		i     int
		left  *TreeNode
		right *TreeNode
	)
	for i = 0; i < len(inorder); i++ {
		if inorder[i] == postorder[len(postorder)-1] {
			break
		}
	}
	if i == 0 {
		left = nil
		right = buildTree(inorder[i+1:], postorder[i:len(postorder)-1])
	} else {
		left = buildTree(inorder[:i], postorder[:i])
		right = buildTree(inorder[i+1:], postorder[i:len(postorder)-1])
	}
	root := &TreeNode{Val: postorder[len(postorder)-1], Left: left, Right: right}
	return root
}
