package leetcode

//import "fmt"

// time: O(m+n), space: O(1)
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	l1, l2 := len(nums1), len(nums2)
	if (l1+l2)%2 == 0 {
		r1 := _innerFindKth(nums1, nums2, 0, 0, (l1+l2)/2)
		r2 := _innerFindKth(nums1, nums2, 0, 0, (l1+l2)/2+1)
		return (float64)(r1+r2) / 2.0
	}
	return float64(_innerFindKth(nums1, nums2, 0, 0, (l1+l2)/2+1))
}

func _innerFindKth(nums1 []int, nums2 []int, i1 int, i2 int, k int) int {
	l1, l2 := len(nums1), len(nums2)
	//fmt.Printf("l1: %v, l2: %v, k: %v, i1: %v, i2: %v\n", l1, l2, k, i1, i2)
	if (l1 - i1) > (l2 - i2) {
		return _innerFindKth(nums2, nums1, i2, i1, k)
	}
	// notice: two stop conditions
	// especially k == 1
	if i1 == l1 {
		return nums2[i2+k-1]
	}
	if k == 1 {
		if nums1[i1] > nums2[i2] {
			return nums2[i2]
		}
		return nums1[i1]
	}
	// move forward by len k/2
	index1, index2 := i1+(k+1)/2-1, i2+(k-(k+1)/2)-1
	if l1-i1 < (k+1)/2 {
		index1, index2 = l1-1, i2+(k-(l1-i1))-1
	}
	// discard the smaller part
	if nums1[index1] < nums2[index2] {
		return _innerFindKth(nums1, nums2, index1+1, i2, k-(index1-i1+1))
	}
	return _innerFindKth(nums1, nums2, i1, index2+1, k-(index2-i2+1))
}
