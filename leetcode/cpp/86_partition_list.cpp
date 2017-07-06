#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *bigPartRoot = nullptr, *bigPartTail = nullptr;
    ListNode *smallPartRoot = nullptr, *smallPartTail = nullptr;
    ListNode *current = head;
    while (current != nullptr) {
      if (current->val < x) {
        if (smallPartRoot == nullptr) smallPartRoot = current;
        if (smallPartTail == nullptr) {
          smallPartTail = current;
        } else {
          smallPartTail->next = current;
          smallPartTail = current;
        }
      } else {
        if (bigPartRoot == nullptr) bigPartRoot = current;
        if (bigPartTail == nullptr) {
          bigPartTail = current;
        } else {
          bigPartTail->next = current;
          bigPartTail = current;
        }
      }
      current = current->next;
    }
    if (bigPartTail != nullptr) bigPartTail->next = nullptr;
    if (smallPartTail == nullptr) {
      return bigPartRoot;
    }
    smallPartTail->next = bigPartRoot;

    return smallPartRoot;
  }
};

int main(int argc, char *argv[]) {
  ListNode n1(2);
  ListNode n2(1);
  n1.next = &n2;
  Solution s;
  auto res = s.partition(&n1, 2);
  while (res != nullptr) {
    cout << res->val << endl;
    res = res->next;
  }
  return 0;
}
