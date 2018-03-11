package leetcode

func reverse(x int) int {
	if x < 0 {
		return -reverse(-x)
	}
	var res int64
	for x > 0 {
		res = res*10 + int64(x)%10
		x = x / 10
	}
	if res > (1<<31 - 1) {
		return 0
	}
	return int(res)
}
