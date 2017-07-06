#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  // time : O(n), space : O(n / 2)
  bool isPalindrome(ListNode *head) {
    // corner cases
    if (head == nullptr || head->next == nullptr) return true;
    ListNode *temp = head;
    int count = 0;
    while (temp != nullptr) {
      count++;
      temp = temp->next;
    }
    vector<int> store(count / 2, 0);
    temp = head;
    for (int i = 0; i < (count / 2); ++i) {
      store[i] = temp->val;
      temp = temp->next;
    }
    if (count % 2 != 0) temp = temp->next;
    int i = 0, len = store.size();
    while (temp != nullptr) {
      if (temp->val != store[len - 1 - i]) return false;
      temp = temp->next;
      i++;
    }
    return true;
  }
  // time : O(n), space : O(1)
  // bool isPalindrome1(ListNode* head) {
  //}
};

int main(int argc, char *argv[]) {
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(2);
  // ListNode *n4 = new ListNode(1);
  ListNode *n4 = new ListNode(2);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  Solution s;
  cout << boolalpha << s.isPalindrome(n1) << endl;
  return 0;
}
