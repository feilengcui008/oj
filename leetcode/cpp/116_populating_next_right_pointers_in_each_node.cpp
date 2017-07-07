class Solution {
 public:
  // time: O(logn*n), space: O(1)
  void connect(TreeLinkNode *root) {
    if (root == nullptr) return;
    // make sure left subtree and right subtree are connected
    connect(root->left);
    connect(root->right);
    // connect two subtrees
    auto left = root->left;
    auto right = root->right;
    while (left != nullptr) {
      left->next = right;
      left = left->right;
      right = right->left;
    }
  }
};
