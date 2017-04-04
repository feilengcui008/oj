package leetcode

//import "fmt"

// time: O(n^2), space: O(1)
func longestPalindrome(s string) string {
	l := len(s)
	if l <= 2 {
		if l == 2 && s[0] != s[1] {
			return ""
		}
		return s
	}
	begin, end, max := 0, 0, 1
	for i := 1; i < l-1; i++ {
		// case 1
		if (s[i] != s[i+1] && s[i] != s[i-1]) || (s[i] == s[i-1] && s[i] == s[i+1]) {
			if s[i-1] == s[i+1] {
				index1, index2, t := i-1, i+1, 1
				for index1 >= 0 && index2 < l && s[index1] == s[index2] {
					t += 2
					index1--
					index2++
				}
				if t > max {
					max, begin, end = t, index1+1, index2-1
				}
			}
		}
		// left equal case
		if s[i-1] == s[i] {
			index1, index2, t := i-1, i, 0
			for index1 >= 0 && index2 < l && s[index1] == s[index2] {
				t += 2
				index1--
				index2++
			}
			if t > max {
				max, begin, end = t, index1+1, index2-1
			}
		}

		// right equal case
		if s[i+1] == s[i] {
			index1, index2, t := i, i+1, 0
			for index1 >= 0 && index2 < l && s[index1] == s[index2] {
				t += 2
				index1--
				index2++
			}
			if t > max {
				max, begin, end = t, index1+1, index2-1
			}
		}
	}
	//fmt.Println(s[begin : end+1])
	return s[begin : end+1]
}
