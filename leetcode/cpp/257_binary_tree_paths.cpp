#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
      vector<string> res;
      if (root == nullptr) return res;
      findAllPath(root, string(""), res);
      return res;
    }

    void findAllPath(TreeNode *root, string s, vector<string> &res) 
    {
      /*
      if (root == nullptr) {
        if (s.length() > 0) {
          res.push_back(s.substr(0, s.length() - 2));
        }
        return;
      }
      */
      int val = root->val;
      string temp;
      s_itoa(val, temp);
      if (root->left == nullptr && root->right == nullptr) { 
        s = s + temp;
        res.push_back(s.substr(0, s.length()));
        return;  
      }
      s = s + temp + "->";
      if (root->left != nullptr) {
        findAllPath(root->left, s, res); 
      }
      if (root->right != nullptr) {
        findAllPath(root->right, s, res);
      }
    }

    int s_itoa(int value, string &s)
    {
      s.clear();
      if (value == 0) {
        s = "0";
        return 1;
      }
      bool flag = true;
      if (value < 0) {
        flag = false;
        value = -value;
      }
      while (value > 0) {
        s.push_back((value % 10) + '0');
        value /= 10;
      }
      if (value != 0) {
        s.push_back(value + '0');
      }
      if (flag == false) {
        s.push_back('-');
      }
      reverse(s.begin(), s.end());
      return s.length();
    }

};


int main(int argc, char *argv[])
{
  Solution s;
  TreeNode *root = new TreeNode(1);
  TreeNode *lchild = new TreeNode(2);
  root->left = lchild;
  auto res = s.binaryTreePaths(root);   
  for (const auto &ele : res) {
    cout << ele << endl;
  }
  delete lchild;
  delete root;  
  return 0;
}
