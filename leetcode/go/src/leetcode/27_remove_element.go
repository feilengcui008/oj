package leetcode

func removeElement(nums []int, val int) int {
	i, e := 0, len(nums)-1
	for i < len(nums) {
		if nums[i] == val {
			for nums[e] == val && e > i {
				e--
			}
			if e > i {
				nums[i] = nums[e]
				nums[e] = val
			} else {
				break
			}
		}
		i++
	}
	return i
}
