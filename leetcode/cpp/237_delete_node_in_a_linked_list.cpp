#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
  public:
    // time : O(1), space : O(1)
    void deleteNode(ListNode *node)
    {
      // node != tail 
      node->val = node->next->val;
      node->next = node->next->next;
    }

    void deleteNode1(ListNode* node) 
    {
      // just move all nodes behind node 
      ListNode *current = node;
      ListNode *pre = current;
      // assert(node != tail)
      while (current->next != nullptr) {
        current->val = current->next->val;
        pre = current;
        current = current->next;
      }
      pre->next = nullptr;
    }

};
