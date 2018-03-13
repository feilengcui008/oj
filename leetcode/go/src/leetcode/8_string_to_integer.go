package leetcode

func myAtoi(str string) int {
	var (
		res  int64
		flag bool
	)
	l, i := len(str), 0

	// skip front space
	for i < l && str[i] == ' ' {
		i++
	}
	if i == l {
		return 0
	}

	// + or -
	switch str[i] {
	case '+':
		i++
	case '-':
		flag = true
		i++
	}
	if i == l {
		return 0
	}

	// parse numeric numbers
	for i < l && str[i] >= '0' && str[i] <= '9' {
		res = res*10 + int64(str[i]-'0')
		// check overflow
		if flag && res > int64(1<<31) {
			return int(-int64(1 << 31))
		}
		if !flag && res > (1<<31-1) {
			return int(1<<31 - 1)
		}
		i++
	}

	if flag {
		return -int(res)
	}
	return int(res)

}
