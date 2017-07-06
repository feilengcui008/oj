struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  // sorted list
  // time : O(n), space : O(1)
  ListNode *deleteDuplicates(ListNode *head) {
    // corner case
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *pre = head;
    ListNode *next = head->next;
    while (next) {
      if (next->val == pre->val) {
        pre->next = next->next;
        next = next->next;
      } else {
        pre = pre->next;
        next = next->next;
      }
    }
    return head;
  }
};
