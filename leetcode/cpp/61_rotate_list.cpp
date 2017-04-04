#include <iostream>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // time: O(n), space: O(1)
    ListNode* rotateRight(ListNode* head, int k)
    {
      // corner case
      if (head == nullptr || head->next == nullptr) return head;
      int n = 0;
      ListNode *temp = head;
      ListNode *newRoot, *tail;
      while (temp->next != nullptr) {
        n++;
        temp = temp->next;
      }
      tail = temp; n++;
      k = k % n;
      if (k == 0) return head;
      // rotate
      temp = head;
      for (int i = 0; i < (n - k - 1); ++i) {
        temp = temp->next;
      }
      newRoot = temp->next;
      tail->next = head;
      temp->next = nullptr;
      return newRoot;
    }
};

int main(int argc, char *argv[])
{
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  Solution s;
  auto res = s.rotateRight(&n1, 3);
  while (res != nullptr) {
    cout << res->val << endl;
    res = res->next;
  }
  return 0;
}
