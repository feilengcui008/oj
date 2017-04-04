package leetcode

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	lists := []*ListNode{l1, l2}
	return mergeKLists(lists)
}
