package leetcode

func isPalindrome(x int) bool {
	if x < 0 {
		//var t int64 = -int64(x)
		//if (t > (1 << 31) - 1) {
		//    return false
		//}
		//return isPalindrome(-x)
		return false
	}
	i, t := 0, x
	for t > 0 {
		i++
		t = t / 10
	}
	for k := 0; k < (i / 2); k++ {
		if (x/pow(10, k))%10 != (x / pow(10, i-1-k) % 10) {
			return false
		}
	}
	return true
}

func pow(x int, n int) int {
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		res := pow(x, n/2)
		return res * res
	}
	return pow(x, n-1) * x

}
