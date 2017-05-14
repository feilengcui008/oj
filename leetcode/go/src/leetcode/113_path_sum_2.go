package leetcode

func innerPathSum(root *TreeNode, sum int, path *[]int, res *[][]int) {
	if root == nil {
		return
	}
	*path = append(*path, root.Val)
	if root.Left == nil && root.Right == nil && sum == root.Val {
		*res = append(*res, *path)
	}
	if root.Left != nil {
		newpath := make([]int, len(*path))
		copy(newpath, *path)
		innerPathSum(root.Left, sum-root.Val, &newpath, res)
	}
	if root.Right != nil {
		newpath := make([]int, len(*path))
		copy(newpath, *path)
		innerPathSum(root.Right, sum-root.Val, &newpath, res)
	}
}

func pathSum(root *TreeNode, sum int) [][]int {
	var path []int
	var res [][]int
	innerPathSum(root, sum, &path, &res)
	return res
}
