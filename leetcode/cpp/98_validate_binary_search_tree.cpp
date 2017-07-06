#include <climits>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    /* // not ok for this method
    // stop condition
    if (root == nullptr ||
    (root->left == nullptr && root->right == nullptr)) return true;
    if (root->left == nullptr && root->right != nullptr) {
    return (root->val < root->right->val) && isValidBST(root->right);
    }
    if (root->right == nullptr && root->left != nullptr) {
    return (root->left->val < root->val) && isValidBST(root->left);
    }
    return (root->left->val < root->val &&
    root->right->val > root->val) &&
    isValidBST(root->left) && isValidBST(root->right);
    */

    // use middle order traverse
    // 注意防止起始判断标准的溢出
    long long preVal = LONG_MIN;
    return middleOrder(root, preVal);
  }

 private:
  bool middleOrder(TreeNode *current, long long &preVal) {
    if (current == nullptr) return true;
    bool left = middleOrder(current->left, preVal);
    // std::cout << "left:" << left << "\n";
    if (preVal >= current->val) return false;
    preVal = current->val;
    bool right = middleOrder(current->right, preVal);
    // std::cout << "right:" << right << "\n";
    return left && right;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *root = new TreeNode(0);
  std::cout << s.isValidBST(root) << std::endl;
  return 0;
}
