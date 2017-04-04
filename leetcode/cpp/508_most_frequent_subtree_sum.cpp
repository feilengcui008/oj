#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    // time: O(n), space: O(n)
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
      unordered_map<int, int> um;
      vector<int> results;
      int max = 0;
      statSum(um, root, max); 
      for (const auto &ele : um) {
        if (ele.second == max) results.push_back(ele.first); 
      }
      return results;
    }

    void statSum(unordered_map<int, int> &um, TreeNode *root, int &max)
    {
      if (root == nullptr) return;
      // must last order traverse
      statSum(um, root->left, max);
      statSum(um, root->right, max);
      int sum = root->val;
      sum += (root->left == nullptr ? 0 : root->left->val);
      sum += (root->right == nullptr ? 0 : root->right->val);
      um[sum] += 1;
      // update the value of root to sum
      root->val = sum;
      if (um[sum] > max) max = um[sum];
    }
};


int main(int argc, char *argv[])
{
  Solution s;
  TreeNode root(5);
  TreeNode lchild(2);
  TreeNode rchild(-3);
  root.left = &lchild;
  root.right = &rchild;
  auto res = s.findFrequentTreeSum(&root);
  for (const auto &ele : res) {
    cout << ele << "\t";
  }
  cout << endl;
  cout << "====" << endl;
  root.val = 5;
  lchild.val = 2;
  rchild.val = -5;
  res = s.findFrequentTreeSum(&root);
  for (const auto &ele : res) {
    cout << ele << "\t";
  }
  cout << endl;
  return 0;
}
