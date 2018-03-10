package leetcode

func firstMissingPositive(nums []int) int {
	for i := 0; i < len(nums); i++ {
		for nums[i] > 0 && nums[i] <= len(nums) {
			if nums[i] == i+1 || nums[nums[i]-1] == nums[i] {
				break
			}
			t := nums[nums[i]-1]
			nums[nums[i]-1] = nums[i]
			nums[i] = t
		}
	}
	for i := 0; i < len(nums); i++ {
		if nums[i] != i+1 {
			return i + 1
		}
	}
	return len(nums) + 1
}