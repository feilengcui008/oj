package leetcode

import "container/heap"

//import "fmt"

type Heap []*ListNode

/*
type ListNode struct {
	Val  int
	Next *ListNode
}
*/

// sort Len interface
func (h Heap) Len() int {
	return len(h)
}

// sort Less interface
func (h Heap) Less(i, j int) bool {
	return h[i].Val < h[j].Val
}

// heap Swap interface
func (h *Heap) Swap(i, j int) {
	(*h)[i], (*h)[j] = (*h)[j], (*h)[i]
}

func (h *Heap) Push(x interface{}) {
	if x == nil {
		return
	}
	item := x.(*ListNode)
	*h = append(*h, item)
}

func (h *Heap) Pop() interface{} {
	if len(*h) == 0 {
		return nil
	}
	item := (*h)[len(*h)-1]
	*h = (*h)[0 : len(*h)-1]
	return item
}

func mergeKLists(lists []*ListNode) *ListNode {
	l := len(lists)
	root := &ListNode{Val: -1, Next: nil}
	saved := root
	if l <= 1 {
		if l == 1 {
			return lists[0]
		}
		return nil
	}
	count := 0
	for i := 0; i < l; i++ {
		if lists[i] != nil {
			count++
		}
	}
	h := make(Heap, count)
	index := 0
	for i := 0; i < l; i++ {
		if lists[i] != nil {
			h[index] = lists[i]
			index++
		}
	}
	heap.Init(&h)

	for len(h) != 0 {
		item := heap.Pop(&h).(*ListNode)
		root.Next = item
		root = root.Next
		if item.Next != nil {
			heap.Push(&h, item.Next)
		}
	}
	return saved.Next
}

/*
func main() {
	h := make(Heap, 3)
	data := []*ListNode{
		&ListNode{Val: 1, Next: nil},
		&ListNode{Val: 2, Next: nil},
		&ListNode{Val: 3, Next: nil},
	}
	for i := 0; i < len(data); i++ {
		h[i] = data[i]
	}
	heap.Init(&h)
	fmt.Println(heap.Pop(&h))
	fmt.Printf("%v\n", h)
	heap.Push(&h, &ListNode{Val: 0, Next: nil})
	fmt.Printf("%v\n", h)
	fmt.Println(heap.Pop(&h))
}
*/
