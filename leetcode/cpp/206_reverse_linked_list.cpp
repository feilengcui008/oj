#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    // corner case
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *h = head;
    ListNode *current = h->next;
    ListNode *next = current->next;
    h->next = nullptr;
    while (current != nullptr &&
           current->next != nullptr) {  // ensure at least two nodes
      next = current->next;
      current->next = h;
      h = current;
      current = next;
    }
    current->next = h;
    return current;
  }
};

int main(int argc, char *argv[]) {
  ListNode *root = new ListNode(0);
  ListNode *first = new ListNode(1);
  // ListNode *second = new ListNode(2);
  root->next = first;
  // first->next = second;

  Solution s;
  ListNode *newroot = s.reverseList(root);
  while (newroot != nullptr) {
    std::cout << newroot->val << std::endl;
    newroot = newroot->next;
  }
  delete root;
  delete first;
  // delete second;
  return 0;
}
