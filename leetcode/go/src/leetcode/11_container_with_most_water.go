package leetcode

// time: O(n), space: O(1)
func maxArea(height []int) int {
	i, j := 0, len(height)-1
	if j == -1 {
		return 0
	}
	max := 0
	for i < j {
		h := height[i]
		if height[i] > height[j] {
			h = height[j]
		}
		if (j-i)*h > max {
			max = (j - i) * h
		}
		for ; i < j && height[i] <= h; i++ {
		}
		for ; i < j && height[j] <= h; j-- {
		}
	}
	return max
}
