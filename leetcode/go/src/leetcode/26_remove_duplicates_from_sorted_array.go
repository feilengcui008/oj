package leetcode

func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	t := 0
	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[t] {
			continue
		}
		t++
		nums[t] = nums[i]
	}
	return t + 1
}
