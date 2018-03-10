package leetcode

func plusOne(digits []int) []int {
	c := 1
	for i := len(digits) - 1; i >= 0; i-- {
		t := (c + digits[i]) % 10
		c = (c + digits[i]) / 10
		digits[i] = t
	}
	if c == 0 {
		return digits
	}
	res := []int{c}
	res = append(res, digits...)
	return res
}
