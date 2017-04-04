package leetcode

//import "fmt"

func isValid(s string) bool {
	stack := []uint8{65}
	size := len(s)
	for i := 0; i < size; i++ {
		switch s[i] {
		case ')':
			if stack[len(stack)-1] == '(' {
				stack = stack[:len(stack)-1]
			} else {
				stack = append(stack, s[i])
			}
		case ']':
			if stack[len(stack)-1] == '[' {
				stack = stack[:len(stack)-1]
			} else {
				stack = append(stack, s[i])
			}

		case '}':
			if stack[len(stack)-1] == '{' {
				stack = stack[:len(stack)-1]
			} else {
				stack = append(stack, s[i])
			}
		default:
			stack = append(stack, s[i])
		}
	}
	//fmt.Println(stack)
	return len(stack) == 1
}
