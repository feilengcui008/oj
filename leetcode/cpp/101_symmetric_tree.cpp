struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    reverseTree(root->right);
    return isEqual(root->left, root->right);
  }

  bool isEqual(TreeNode *l, TreeNode *r) {
    if (l == nullptr && r == nullptr) return true;
    if (l != nullptr && r != nullptr && l->val == r->val) {
      return isEqual(l->left, r->left) && isEqual(l->right, r->right);
    }
    return false;
  }

  void reverseTree(TreeNode *root) {
    if (root == nullptr) return;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    reverseTree(root->left);
    reverseTree(root->right);
  }
};
