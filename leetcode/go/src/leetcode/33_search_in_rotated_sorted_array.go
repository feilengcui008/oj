package leetcode

// time: O(logn), space: O(1)
func search(nums []int, target int) int {
	begin, end := 0, len(nums)-1
	if end == -1 {
		return -1
	}
	for begin < end {
		middle := (begin + end) / 2
		if nums[middle] == target {
			return middle
		}
		// middle lies in left part
		if nums[middle] >= nums[begin] {
			// target lies in left part
			if target >= nums[begin] && target < nums[middle] {
				end = middle - 1
			} else {
				begin = middle + 1
			}
		} else { // middle lies in right part
			if target > nums[middle] && target <= nums[end] {
				begin = middle + 1
			} else {
				end = middle - 1
			}
		}
	}
	if nums[begin] == target {
		return begin
	}
	return -1
}
