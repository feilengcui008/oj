package leetcode

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	left := sortedArrayToBST(nums[:len(nums)/2])
	right := sortedArrayToBST(nums[len(nums)/2+1:])
	root := &TreeNode{Val: nums[len(nums)/2], Left: left, Right: right}
	return root
}
