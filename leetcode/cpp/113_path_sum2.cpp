class Solution {
 public:
  // time: O(n), space: O(n^2)
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> res;
    vector<int> init;
    innerPath(root, sum, init, res);
    return res;
  }

  void innerPath(TreeNode *root, int sum, vector<int> &saved,
                 vector<vector<int>> &all) {
    if (root != nullptr && root->left == nullptr && root->right == nullptr &&
        root->val == sum) {
      saved.push_back(root->val);
      all.push_back(saved);
    }
    if (root != nullptr && (root->left != nullptr || root->right != nullptr)) {
      saved.push_back(root->val);
      if (nullptr != root->left) {
        auto vec = saved;
        innerPath(root->left, sum - root->val, vec, all);
      }
      if (nullptr != root->right) {
        auto vec = saved;
        innerPath(root->right, sum - root->val, vec, all);
      }
    }
  }
};
