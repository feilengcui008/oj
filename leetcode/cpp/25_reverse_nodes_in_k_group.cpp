#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  // time: O(n), space: O(k)
  ListNode *reverseKGroup(ListNode *head, int k) {
    vector<ListNode *> currentKNodes(k, nullptr);
    ListNode h(-1), *root = &h, *saved = root;
    root->next = head;
    ListNode *t = head;

    // init currentKNodes
    int i;
    for (i = 0; i < k; ++i) {
      if (t == nullptr) break;
      currentKNodes[i] = t;
      t = t->next;
    }
    // length of list < k
    if (i < k) return head;

    while (root != nullptr && root->next != nullptr) {
      // begin reverse
      ListNode *nextRoundHead = currentKNodes[k - 1]->next;
      root->next = currentKNodes[k - 1];
      for (int j = k - 1; j > 0; --j) {
        currentKNodes[j]->next = currentKNodes[j - 1];
      }
      root = currentKNodes[0];
      root->next = nextRoundHead;
      // update currentKNodes
      t = root->next;
      for (i = 0; i < k; ++i) {
        if (t == nullptr) break;
        currentKNodes[i] = t;
        t = t->next;
      }
      if (i < k) break;
    }
    return saved->next;
  }
};

int main(int argc, char *argv[]) {
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(4);
  ListNode *n5 = new ListNode(5);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  Solution s;
  auto res = s.reverseKGroup(n1, 2);
  while (res != nullptr) {
    cout << res->val << endl;
    res = res->next;
  }
  return 0;
}
