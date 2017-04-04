package leetcode

// time: O(n*m), space: O(1)
func longestCommonPrefix(strs []string) string {
	size := len(strs)
	if size <= 1 {
		if size == 1 {
			return strs[0]
		}
		return ""
	}
	f := func(s1, s2 string) string {
		l1, l2 := len(s1), len(s2)
		if l2 < l1 {
			l1 = l2
		}
		i := 0
		for ; i < l1; i++ {
			if s1[i] != s2[i] {
				break
			}
		}
		return s1[:i]
	}
	t := strs[0]
	for i := 1; i < size; i++ {
		t = f(t, strs[i])
	}
	return t
}
