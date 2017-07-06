#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<TreeNode *> generateTrees(int n) { return innerGenerate(n, 0); }

  vector<TreeNode *> innerGenerate(int n, int plus) {
    vector<TreeNode *> res;
    if (n == 0) return res;
    if (n == 1) {
      res.push_back(new TreeNode(1 + plus));
      return res;
    }
    for (int i = 1; i <= n; ++i) {
      auto left = innerGenerate(i - 1, plus);
      auto right = innerGenerate(n - i, i + plus);
      if (left.size() == 0) {
        for (auto &ele : right) {
          TreeNode *root = new TreeNode(i + plus);
          root->right = ele;
          res.push_back(root);
        }
      } else if (right.size() == 0) {
        for (auto &ele : left) {
          TreeNode *root = new TreeNode(i + plus);
          root->left = ele;
          res.push_back(root);
        }
      } else {
        for (auto &ele : left) {
          for (auto &e : right) {
            TreeNode *root = new TreeNode(i + plus);
            root->left = ele;
            root->right = e;
            res.push_back(root);
          }
        }
      }
    }
    return res;
  }
};
