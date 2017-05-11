package leetcode

import (
	"testing"
)

func Test_14(t *testing.T) {
	data := [][]string{
		[]string{"pre", "prefix"},
		[]string{"q", "p"},
	}
	target := []string{"pre", ""}
	size := len(data)
	for i := 0; i < size; i++ {
		if longestCommonPrefix(data[i]) != target[i] {
			t.Errorf("number 14 failed: %v", target[i])
		}
	}
}
