package leetcode

func generateParenthesis(n int) []string {
	var strs []string
	innerSolution(n, 0, 0, "", &strs)
	return strs
}

func innerSolution(n int, l int, r int, str string, strs *[]string) {
	if l < r || l > n || r > n {
		return
	}
	if l == r && l == n {
		*strs = append(*strs, str)
		return
	}

	innerSolution(n, l+1, r, str+"(", strs)
	innerSolution(n, l, r+1, str+")", strs)
}
