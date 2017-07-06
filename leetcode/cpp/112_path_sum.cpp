class Solution {
 public:
  // time: O(n), space: O(1)
  bool hasPathSum(TreeNode* root, int sum) {
    if (root != nullptr && root->left == nullptr && root->right == nullptr &&
        root->val == sum) {
      return true;
    }
    if (root != nullptr && (root->left != nullptr || root->right != nullptr)) {
      bool ret = false;
      if (nullptr != root->left) ret |= hasPathSum(root->left, sum - root->val);
      if (nullptr != root->right)
        ret |= hasPathSum(root->right, sum - root->val);
      return ret;
    }
    return false;
  }
};
