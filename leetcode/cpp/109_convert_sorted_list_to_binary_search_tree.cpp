class Solution {
 public:
  // time: O(logn*n), space: O(n)
  TreeNode *sortedListToBST(ListNode *head) {
    int c = 0;
    auto root = head;
    while (root != nullptr) {
      c++;
      root = root->next;
    }
    return innerSort(head, c);
  }

  TreeNode *innerSort(ListNode *head, int len) {
    if (len == 0) return nullptr;
    if (len == 1) return new TreeNode(head->val);

    int middle = len / 2;
    ListNode *rroot;
    ListNode *pre = head;
    for (int i = 0; i < middle - 1; i++) {
      pre = pre->next;
    }
    rroot = pre->next->next;
    TreeNode *root = new TreeNode(pre->next->val);
    pre->next = nullptr;

    root->left = innerSort(head, middle);
    root->right = innerSort(rroot, len - middle - 1);
    return root;
  }
};
