#include <iostream>
#include <cmath>
#include <memory>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    int countNodes(TreeNode* root) { return _byDepth(root); }
  private:
    // time exceed O(2^n)
    int _count(TreeNode *root) 
    {
      if (root == nullptr) {
        return 0;
      } else {
        return _count(root->left) + _count(root->right) + 1;  
      }
    }

    // time exceed  O(n)
    void _traverse(TreeNode *root, int &res)
    {
      //先序遍历一遍
      if (root != nullptr) {
        res += 1;
        _traverse(root->left, res);
        _traverse(root->right, res);
      } 
    }

    // 遍历肯定不行，超时，所以只有利用高度O(logn)的复杂度
    / /充分利用子树可能是完全二叉树的性质
    int _byDepth(TreeNode *root)
    {
      if (root == nullptr)
        return 0;
      int left = _getLeftMostDepth(root);
      int right = _getRightMostDepth(root);
      if (left == right)
        return pow(2, left) - 1;
      return _byDepth(root->left) + _byDepth(root->right) + 1;
    }

    // O(n)
    int _getDepth(TreeNode *root)
    {
      if (root == nullptr)
        return 0;
      else {
        int left = _getDepth(root->left);
        int right = _getDepth(root->right);
        return left > right ? left + 1 : right + 1;
      }
    }
    // O(logn)
    int _getLeftMostDepth(TreeNode *root)
    {
      int count = 0;
      while (root != nullptr) {
        count++;
        root = root->left;
      }
      return count;
    }

    // O(logn)
    int _getRightMostDepth(TreeNode *root)
    {
      int count = 0;
      while(root != nullptr) {
        count++;
        root = root->right;
      }
      return count;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(1);
  std::cout << s.countNodes(root);
  delete root->left;
  delete root;
  return 0;
}
