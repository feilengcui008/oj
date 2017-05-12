package leetcode

func sortedListToBSTn(head *ListNode, n int) *TreeNode {
	if n == 0 {
		return nil
	}
	if n == 1 {
		return &TreeNode{Val: head.Val, Left: nil, Right: nil}
	}
	var leftPart *ListNode = head
	var rightPart *ListNode = nil
	for i := 0; i < n/2-1; i++ {
		leftPart = leftPart.Next
	}
	root := &TreeNode{Val: leftPart.Next.Val}
	rightPart = leftPart.Next.Next
	leftPart.Next = nil
	root.Left = sortedListToBSTn(head, n/2)
	if rightPart == nil {
		root.Right = sortedListToBSTn(rightPart, 0)
	} else {
		root.Right = sortedListToBSTn(rightPart, n-n/2-1)
	}
	return root
}

func sortedListToBST(head *ListNode) *TreeNode {
	n := 0
	t := head
	for t != nil {
		n++
		t = t.Next
	}
	return sortedListToBSTn(head, n)
}
