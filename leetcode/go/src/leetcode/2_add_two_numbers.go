package leetcode

// time: O(n), space: O(1)
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	c := 0
	root1 := l1
	root2 := l2
	// add common part
	for root1 != nil && root2 != nil {
		t := c
		c = (root1.Val + root2.Val + t) / 10
		root1.Val = (root1.Val + root2.Val + t) % 10
		root2.Val = root1.Val
		root1 = root1.Next
		root2 = root2.Next
	}
	//fmt.Printf("pos1 c:%v\n", c)
	// add with last part
	flag := 1
	newRoot := root1
	if newRoot == nil {
		newRoot = root2
		flag = 2
	}
	for newRoot != nil && c != 0 {
		t := c
		c = (t + newRoot.Val) / 10
		newRoot.Val = (t + newRoot.Val) % 10
		//fmt.Printf("last value:%v\n", newRoot.Val)
		newRoot = newRoot.Next
	}
	//fmt.Printf("pos2 c:%v\n", c)

	// handle last c
	if c != 0 {
		n := &ListNode{c, nil}
		newRoot = l1
		if flag != 1 {
			newRoot = l2
		}
		for newRoot.Next != nil {
			newRoot = newRoot.Next
		}
		newRoot.Next = n
	}
	if flag != 1 {
		return l2
	}
	return l1
}
