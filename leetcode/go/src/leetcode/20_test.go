package leetcode

import (
	"testing"
)

func Test_20(t *testing.T) {
	data := []string{
		"()[]",
		"(]",
		"]",
	}
	target := []bool{true, false, false}
	size := len(data)
	for i := 0; i < size; i++ {
		if isValid(data[i]) != target[i] {
			t.Errorf("number 20 failed\n")
		}
	}
}
