#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    queue<TreeNode *> q;
    q.push(root);
    int lastLevelCount = 1, c = 0;
    int currentCount = 1;
    vector<int> v;
    while (!q.empty()) {
      auto e = q.front();
      q.pop();
      v.push_back(e->val);
      c++;
      currentCount--;
      if (e->left != nullptr) {
        q.push(e->left);
        currentCount++;
      }
      if (e->right != nullptr) {
        q.push(e->right);
        currentCount++;
      }
      if (c == lastLevelCount) {
        res.push_back(v);
        v.clear();
        c = 0;
        lastLevelCount = currentCount;
      }
    }
    return res;
  }
};
