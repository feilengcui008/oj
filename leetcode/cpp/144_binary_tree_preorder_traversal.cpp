#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
      vector<int> res;
      // corner case 
      if (root == NULL) return res;
      stack<TreeNode *> s;
      TreeNode *p = root;
      while (p || !s.empty()) {
        while (p) {
          res.push_back(p->val);
          s.push(p);
          p = p->left;
        }
        p = s.top();
        s.pop();
        p = p->right;
      }
      return res;
    }
};
