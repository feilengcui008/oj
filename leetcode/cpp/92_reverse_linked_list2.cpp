#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* reverseBetween(ListNode *head, int m, int n)
    {
      ListNode dummy(-1); dummy.next = head;
      ListNode *pre = &dummy, *reverseRoot = head, *reverseTail = nullptr;
      for (int i = 1; i < m; ++i) {
        reverseRoot = reverseRoot->next;
        pre = pre->next; 
      }
      
      ListNode *tailRoot = reverseRoot;
      for (int i = 0; i < (n-m); ++i) {
        tailRoot = tailRoot->next;
      }
      reverseTail = tailRoot;
      tailRoot = tailRoot->next;
      reverseTail->next = nullptr;

      auto h = reverseList(reverseRoot);

      pre->next = h;
      while (h != nullptr && h->next != nullptr) h = h->next;
      h->next = tailRoot;
      
      return dummy.next;

    }

    ListNode* reverseList(ListNode* head) {
      // corner case 
      if (head == nullptr || head->next == nullptr) 
        return head;
      ListNode *h = head;
      ListNode *current = h->next;
      ListNode *next = current->next;
      h->next = nullptr;
      while (current != nullptr && current->next != nullptr) { // ensure at least two nodes 
        next = current->next;
        current->next = h;
        h = current;
        current = next;
      }
      current->next = h;
      return current;
    }

};

int main(int argc, char *argv[])
{
  ListNode *root = new ListNode(0);
  ListNode *first = new ListNode(1);
  ListNode *second = new ListNode(2);
  ListNode *third = new ListNode(3);
  root->next = first;
  first->next = second;
  second->next = third;

  Solution s;
  ListNode *newroot = s.reverseBetween(root, 1, 3);
  while (newroot != nullptr) {
    std::cout << newroot->val << std::endl;
    newroot = newroot->next;
  }
  delete root;
  delete first;
  delete second;
  delete third;
  return 0;
}
