#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *pre = head;
    ListNode *next = head;
    while (next != nullptr && next->next != nullptr) {
      pre = pre->next;
      next = next->next->next;
      if (pre == next) return true;
    }
    return false;
  }

  static ListNode *createList(int n) {
    ListNode *root = new ListNode(5);
    ListNode **temp = &root->next;
    for (int i = 1; i < n; i++) {
      // notice the pointer operations
      *temp = new ListNode(i);
      temp = &(*temp)->next;
    }
    return root;
  }

  static void test() {
    Solution s;
    ListNode *temp = Solution::createList(5);
    std::cout << std::boolalpha << s.hasCycle(temp) << std::endl;
  }
};
