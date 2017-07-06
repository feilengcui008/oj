#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  // O(n)
  // to do : Tarjan algorithm and RMQ algorithm
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> v1, v2;
    if (!find(root, p, v1) || !find(root, q, v2)) return nullptr;
    return findCommon(v1, v2);
  }

  TreeNode *anotherMethod(TreeNode *root, TreeNode *p, TreeNode *q) {
    // 1. find the first node p and make it the LCA
    // 2. find the child tree of p to see if q is in it
    // 3. if not in 2, then make p become the parent of itself,
    // and find q in the other child tree of its parent
    return nullptr;
  }

  TreeNode *findCommon(vector<TreeNode *> &v1, vector<TreeNode *> &v2) {
    int size1 = v1.size();
    int size2 = v2.size();
    if (size1 > size2) return findCommon(v2, v1);
    int i = 0;
    int j = i + size2 - size1;
    while (i < size1 && j < size2) {
      if (v1[i] == v2[j]) return v1[i];
      i++;
      j++;
    }
    return nullptr;
  }

  // find the path from node root to node target
  bool find(TreeNode *root, TreeNode *target, vector<TreeNode *> &v) {
    // corner case
    if (root == nullptr || target == nullptr) return false;
    // found
    // do not use root->val==target->val here because maybe there are two nodes
    // have the same value
    if (root == target) {
      v.push_back(root);
      return true;
    } else {
      if (find(root->left, target, v)) {
        v.push_back(root);
        return true;
      } else if (find(root->right, target, v)) {
        v.push_back(root);
        return true;
      } else {
        return false;
      }
    }
    return false;
  }

  /*
  //unfortunately time exceeded...
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

  if(find(root->left, p) && find(root->left, q)){
  return lowestCommonAncestor(root->left, p, q);
  }else if(find(root->right, p) && find(root->right, q)){
  return lowestCommonAncestor(root->right, p, q);
  }else {
  return root;
  }
  return nullptr;
  }

  bool find(TreeNode *root, TreeNode *target)
  {
  if(root == target)
  return true;
  if(root == nullptr)
  return false;
  return find(root->left, target) || find(root->right, target);
  }
  */
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  root->left = left;
  root->right = right;
  Solution s;
  TreeNode *t = s.lowestCommonAncestor(root, left, root);
  if (t == nullptr) {
    cout << "nullptr\n";
  } else {
    cout << t->val << "\n";
  }
  delete left;
  delete right;
  delete root;
  return 0;
}
