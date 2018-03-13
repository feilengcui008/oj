package leetcode

func swapPairs(head *ListNode) *ListNode {
	return swapPairsNonrecursive(head)
}

func swapPairsRecursive(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	c := head
	cn := head.Next
	n := swapPairs(head.Next.Next)
	cn.Next = c
	c.Next = n
	return cn
}

func swapPairsNonrecursive(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var dummy ListNode
	c, p := head, &dummy
	for c != nil && c.Next != nil {
		cn := c.Next
		t := cn.Next
		cn.Next = c
		c.Next = t
		p.Next = cn
		p = c
		c = t
	}
	return dummy.Next
}
