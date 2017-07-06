struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // corner case
    if (head == nullptr || n <= 0) return head;
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode *pre = &dummyHead;
    ListNode *next = dummyHead.next;
    // one step first
    for (int i = 0; i < n; ++i) {
      next = next->next;
    }
    while (next) {
      next = next->next;
      pre = pre->next;
    }
    pre->next = pre->next->next;
    return dummyHead.next;
  }
};
