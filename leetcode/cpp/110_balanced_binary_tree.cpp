struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 树相关的类似子序列的问题优先考虑递归比较简单
class Solution {
 public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) return true;
    int temp = getDepth(root->left) - getDepth(root->right);
    return (temp == 0 || temp == 1 || temp == -1) && isBalanced(root->left) &&
           isBalanced(root->right);
  }

 private:
  int getDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    int left = getDepth(root->left);
    int right = getDepth(root->right);
    return left > right ? left + 1 : right + 1;
  }
};
