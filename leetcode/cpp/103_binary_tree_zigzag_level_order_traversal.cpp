#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
      vector<vector<int>> res;
      if (root == nullptr) return res;
      queue<TreeNode*> q;
      q.push(root);
      int lastLevelCount = 1, c = 0;
      int currentCount = 1;
      bool flag = false; // right push first
      vector<int> v;
      vector<TreeNode*> temp;
      while (!q.empty()) {
        auto e = q.front();
        q.pop();
        v.push_back(e->val);
        temp.push_back(e);
        c++; currentCount--;
        if (c == lastLevelCount) {
          res.push_back(v); v.clear(); 
          c = 0;
          for (int i = temp.size() - 1; i >= 0; --i) {
            if (flag) {
              if (temp[i]->left != nullptr) {
                q.push(temp[i]->left); currentCount++;
              }
              if (temp[i]->right != nullptr) {
                q.push(temp[i]->right); currentCount++;
              }
            } else {
              if (temp[i]->right != nullptr) {
                q.push(temp[i]->right); currentCount++;
              }
              if (temp[i]->left != nullptr) {
                q.push(temp[i]->left); currentCount++;
              }
            }
          }
          lastLevelCount = currentCount;
          flag = !flag;
          temp.clear();
        }
      }
      return res;
    }
};
