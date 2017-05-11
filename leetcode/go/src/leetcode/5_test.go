package leetcode

import (
	"testing"
)

func Test_5(t *testing.T) {
	data := []string{"babad", "cbbd", "abcda", "ccd", "ccc"}
	target := [][]string{
		[]string{"bab", "aba"},
		[]string{"bb"},
		[]string{"a"},
		[]string{"cc"},
		[]string{"ccc"},
	}
	size := len(data)
	for i := 0; i < size; i++ {
		r := longestPalindrome(data[i])
		var j int
		for j = 0; j < len(target[i]); j++ {
			if target[i][j] == r {
				break
			}
		}
		if j == len(target[i]) {
			t.Errorf("number 5 failed")
		}
	}
}
