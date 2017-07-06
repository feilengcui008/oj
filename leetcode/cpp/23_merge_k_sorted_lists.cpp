#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  // time: O(logk*k*n), space: O(k)
  // 注意make_heap, pop_heap, push_heap, sort_heap都需要传入cmp
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int k = lists.size();
    if (k == 0) return nullptr;
    if (k == 1) return lists[0];
    // use heap
    vector<ListNode *> heap;
    for (int i = 0; i < k; ++i) {
      if (lists[i] != nullptr) {
        heap.push_back(lists[i]);
      }
    }
    auto cmp = [](ListNode *l1, ListNode *l2) { return l1->val > l2->val; };
    make_heap(begin(heap), end(heap), cmp);
    ListNode head(-1), *root = &head;
    while (1) {
      if (heap.size() == 0) break;
      pop_heap(begin(heap), end(heap), cmp);
      auto p = heap[heap.size() - 1];
      heap.pop_back();
      root->next = p;
      root = root->next;
      if (p->next != nullptr) {
        heap.push_back(p->next);
        push_heap(begin(heap), end(heap), cmp);
      }
    }
    return head.next;
  }
};

int main(int argc, char *argv[]) {
  ListNode n11(1);
  ListNode n12(2);
  ListNode n13(2);
  ListNode n21(1);
  ListNode n22(1);
  ListNode n23(2);
  n11.next = &n12;
  n12.next = &n13;
  n21.next = &n22;
  n22.next = &n23;
  Solution s;
  vector<ListNode *> v{&n11, &n21};
  auto res = s.mergeKLists(v);
  while (res != nullptr) {
    cout << res->val << endl;
    res = res->next;
  }

  return 0;
}
