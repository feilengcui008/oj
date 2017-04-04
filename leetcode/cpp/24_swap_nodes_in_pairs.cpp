#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
  public:
    ListNode* swapPairs(ListNode* head) 
    {
      if (head == nullptr || head->next == nullptr) return head;
      // at least two nodes
      ListNode n(-1), *pre = &n;
      pre->next = head;
      auto saved = pre;
      auto first = head, second = first->next;
      ListNode *temp = nullptr;
      while (first != nullptr && first->next != nullptr) {
        second = first->next;
        temp = second->next;
        pre->next = second;
        second->next = first;
        first->next = temp;
        pre = first;
        first = temp;
        if (first != nullptr) second = first->next;
        else second = nullptr;
      }
      return saved->next;
    }
};


int main(int argc, char *argv[])
{
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(4);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  Solution s;
  auto res = s.swapPairs(n1);
  while (res != nullptr) {
    cout << res->val << endl;
    res = res->next;
  }
  delete n1;
  delete n2;
  delete n3;
  delete n4;
  return 0;
}
