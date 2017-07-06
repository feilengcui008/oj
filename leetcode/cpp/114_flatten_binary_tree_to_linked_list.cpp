class Solution {
 public:
  // time: O(n), space: O(1)
  void flatten(TreeNode* root) {
    if (root == nullptr) return;
    auto left = root->left;
    auto right = root->right;
    flatten(left);
    flatten(right);
    root->left = nullptr;
    root->right = left;

    auto temp = left;
    while (temp != nullptr && temp->right != nullptr) {
      temp = temp->right;
    }
    if (temp != nullptr) {
      temp->right = right;
    } else {
      root->right = right;
    }
  }
};
