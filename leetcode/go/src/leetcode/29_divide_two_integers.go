package leetcode

func divide(dividend int, divisor int) int {
	// signed flag
	f := -1
	if dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0 {
		f = 1
	}

	var (
		res int64
		i   int64 = 1
		m         = int64(divisor)
		d         = int64(dividend)
	)
	if divisor < 0 {
		m = -m
	}
	if dividend < 0 {
		d = -d
	}

	// minus by exponentially
	for d >= m {
		d = d - m
		res = res + i
		i = i << 1
		m = m << 1
	}

	// minus left part
	m = int64(divisor)
	if m < 0 {
		m = -m
	}
	for d >= m {
		d = d - m
		res = res + 1
	}

	// check overflow
	if f == 1 && res > (1<<31-1) {
		return (1<<31 - 1)
	}

	if f == -1 && res > (1<<31) {
		return -(1 << 31)
	}

	return f * int(res)
}
