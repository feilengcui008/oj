package leetcode

func levelOrderBottom(root *TreeNode) [][]int {
	q := new(SimpleQueue)
	var (
		res  [][]int
		temp [][]int
		t    []int
	)
	if root == nil {
		return res
	}
	q.Push(root)
	current, next := 1, 0
	for !q.Empty() {
		n, _ := q.Front()
		f, ok := n.(*TreeNode)
		if !ok {
			return res
		}
		q.Pop()
		current--
		if f.Left != nil {
			next++
			q.Push(f.Left)
		}
		if f.Right != nil {
			next++
			q.Push(f.Right)
		}
		t = append(t, f.Val)
		if current == 0 {
			temp = append(temp, t)
			t = nil
			current = next
			next = 0
		}
	}
	for i := len(temp) - 1; i >= 0; i-- {
		res = append(res, temp[i])
	}
	return res
}
