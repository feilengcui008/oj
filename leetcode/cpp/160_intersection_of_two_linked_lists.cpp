struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (headA == nullptr || headB == nullptr) return nullptr;
      int len1 = 0;
      int len2 = 0;
      ListNode *temp1 = headA;
      ListNode *temp2 = headB;
      while (temp1 != nullptr) {
        len1++;
        temp1 = temp1->next;
      }
      while (temp2 != nullptr) {
        len2++;
        temp2 = temp2->next;
      }
      temp1 = headA;
      temp2 = headB;
      if (len1 < len2) {
        for (int i = 0; i < (len2 - len1); ++i) {
          temp2 = temp2->next;
        }
      } else {
        for (int i = 0; i < (len1 - len2); ++i) {
          temp1 = temp1->next;
        }
      }
      while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1 == temp2) return temp1;
      }
      return nullptr;
    }
    // time exceed
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
      // return point
      if (headA == nullptr || headB == nullptr) return nullptr;
      if (headA == headB) return headA;
      ListNode *temp = getIntersectionNode(headA->next, headB);
      if (temp != nullptr) return temp;
      temp = getIntersectionNode(headA, headB->next);
      if (temp != nullptr) return temp;
      temp = getIntersectionNode(headA->next, headB->next);
      if (temp != nullptr) return temp;
      return nullptr;
    }
};
