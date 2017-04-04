package leetcode

// time: O(n), space: O(1)
func lengthOfLongestSubstring(s string) int {
	n := len(s)
	if n <= 1 {
		return n
	}
	var (
		l   = 0
		r   = 0
		max = 0
	)
	um := make(map[uint8]int)
	// move right index along
	for ; r < n; r++ {
		// if find a nearest position of a
		// repeated char, we need update
		if ele, ok := um[s[r]]; ok {
			// move left index if need
			if ele+1 > l {
				l = ele + 1
			}
		}
		um[s[r]] = r
		if r-l+1 > max {
			max = r - l + 1
		}
	}
	return max
}
