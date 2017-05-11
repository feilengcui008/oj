package leetcode

import (
	"sort"
	"testing"
)

func Test_1(t *testing.T) {
	arr := []int{2, 7, 11, 15}
	target := 9
	res := twoSum(arr, target)
	real := []int{0, 1}
	sort.Ints(res)
	if len(res) != len(real) {
		t.Errorf("number 1 failed: %v != %v", arr, real)
	}
	for i := 0; i < len(res); i++ {
		if res[i] != real[i] {
			t.Fatalf("number 1 failed: %v != %v", arr, real)
		}
	}
}
