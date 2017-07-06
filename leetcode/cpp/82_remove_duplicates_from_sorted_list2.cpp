#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    // corner case
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode *first = &dummyHead;
    ListNode *second = first->next;
    ListNode *third = second->next;
    bool flag = false;
    while (second && third) {
      if (third->val == second->val) {
        flag = true;  // mark it we need delete first value of the same nodes
        first->next = second->next;  // delete second
        second = third;
        third = third->next;
      } else {  // ok, next node is not equal to second
        if (flag == true) {
          // delete second
          first->next = third;
          second = third;
          third = third->next;
          flag = false;
        } else {
          first = second;
          second = third;
          if (third) {  // notice here
            third = third->next;
          }
        }
      }
    }
    if (flag == true) {
      first->next = second->next;
    }
    return dummyHead.next;
  }
};

int main(int argc, char *argv[]) {
  // case1 : 1->1
  // case2 : 1->1->2
  // case3 : 1->1->2->2
  ListNode n1(1);
  ListNode n2(1);
  ListNode n3(2);
  ListNode n4(2);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  Solution s;
  ListNode *res = s.deleteDuplicates(&n1);
  while (res) {
    cout << res->val << endl;
    res = res->next;
  }
  return 0;
}
