struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
      if (head == nullptr) return head;
      ListNode dummy(0);
      dummy.next = head;
      ListNode *pre = &dummy;
      ListNode *next = pre->next;
      while (next != nullptr) {
        if (next->val == val) {
          pre->next = next->next;
          next = next->next;
        } else {
          pre = next;
          next = next->next;
        }
      }
      return dummy.next;
    }
};
