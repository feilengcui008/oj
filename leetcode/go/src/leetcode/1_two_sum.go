package leetcode

// time: O(n), space: O(n)
func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	var res []int
	for k, v := range nums {
		o := target - v
		if ele, ok := m[o]; ok {
			res = append(res, k, ele)
		} else {
			m[v] = k
		}
	}
	return res
}
