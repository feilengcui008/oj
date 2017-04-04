#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
      int c = 0;
      ListNode *res = nullptr, **head = nullptr;
      // corner cases
      if (l1 == nullptr)
        return l2;
      if (l2 == nullptr)
        return l1;

      // handle head
      if (l1 != nullptr && l2 != nullptr) {
        if (l1->val + l2->val>=10) {
          c = 1;
          res = new ListNode(l1->val + l2->val - 10);
        } else {
          res = new ListNode(l1->val + l2->val);
        }
        head = &res->next;
        l1 = l1->next;
        l2 = l2->next;
      }

      // add two elements
      int temp = 0;
      while (l1 != nullptr || l2 != nullptr || c!=0) {
        temp = 0;
        temp += c;
        if (l1 != nullptr) {
          temp += l1->val;
          l1 = l1->next;
        }
        if (l2 != nullptr) {
          temp += l2->val;
          l2 = l2->next;
        }
        if (temp >= 10) {
          c = 1;
          *head = new ListNode(temp - 10);
        } else {
          c = 0;
          *head = new ListNode(temp);
        }
        head = &(*head)->next;
      }
      return res;
    }

    static void test()
    {
      ListNode *l1 = Solution::createList(5);
      ListNode *l2 = Solution::createList(5);
      Solution s;
      Solution::printList(l1);
      Solution::printList(l2);
      ListNode *res = s.addTwoNumbers(l1, l2);
      Solution::printList(res);
    }

    static ListNode *createList(int n)
    {
      ListNode *root = new ListNode(5);
      ListNode **temp = &root->next;
      for (int i = 1; i < n; i++) {
        //notice the pointer operations
        *temp = new ListNode(i);
        temp = &(*temp)->next;
      }
      return root;
    }
    static void printList(ListNode *root)
    {
      while (root != NULL) {
        std::cout << root->val << "\t";
        root = root->next;
      }
      std::cout << std::endl;
    }
};
