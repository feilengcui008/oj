
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    // corner case
    if (root == nullptr) return root;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    root->left = right;
    root->right = left;
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};
