#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *oddEvenList(ListNode *head) {
    // corner cases : 0 or <= 2 nodes
    if (head == nullptr || head->next == nullptr ||
        head->next->next == nullptr) {
      return head;
    }
    // whose next is odd number
    int currentIndex = 2;
    // whose next node is odd, should be deleted and insert
    // insert after toBeInserted
    ListNode *current = head->next;
    // we will insert next odd node after this node
    ListNode *toBeInserted = head;
    while (current != nullptr) {
      // current even position and has next odd node
      if (currentIndex % 2 == 0 && current->next != nullptr) {
        ListNode *temp1 = current->next;
        current->next = temp1->next;
        ListNode *temp2 = toBeInserted->next;
        toBeInserted->next = temp1;
        temp1->next = temp2;
        currentIndex += 1;
        toBeInserted = toBeInserted->next;
      }
      current = current->next;
      currentIndex += 1;
    }
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(4);
  ListNode *n5 = new ListNode(5);
  ListNode *n6 = new ListNode(6);
  ListNode *n7 = new ListNode(7);
  ListNode *n8 = new ListNode(8);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;
  n7->next = n8;
  Solution s;
  ListNode *h = s.oddEvenList(n1);
  while (h != nullptr) {
    cout << h->val << endl;
    h = h->next;
  }
  return 0;
}
