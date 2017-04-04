struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
      // corner case
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;
      ListNode dummy(0);
      ListNode *dummyroot = &dummy;
      ListNode *root1 = l1;
      ListNode *root2 = l2;
      while (root1 != nullptr && root2 != nullptr) {
        if (root1->val < root2->val) {
          dummyroot->next = root1;
          dummyroot = root1;
          root1 = root1->next;
        } else {
          dummyroot->next = root2;
          dummyroot = root2;
          root2 = root2->next;
        }
      } 
      dummyroot->next = root1 != nullptr ? root1 : root2;
      return dummy.next;
    }

};
