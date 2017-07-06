#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    if (root == NULL) return res;
    queue<TreeNode *> q;
    q.push(root);
    int currentLevelNum = 1;
    vector<int> level;
    while (!q.empty()) {
      TreeNode *temp = q.front();
      level.push_back(temp->val);
      q.pop();
      if (temp->left != NULL) {
        q.push(temp->left);
      }
      if (temp->right != NULL) {
        q.push(temp->right);
      }
      currentLevelNum -= 1;
      if (currentLevelNum == 0) {
        currentLevelNum = q.size();
        res.push_back(level);
        level.clear();
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
