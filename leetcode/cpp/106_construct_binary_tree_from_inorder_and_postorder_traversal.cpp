#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(n^2), space: O(n^2)
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = inorder.size(), i;
    if (size == 0) return nullptr;

    for (i = 0; i < size; ++i) {
      if (inorder[i] == postorder[size - 1]) break;
    }
    TreeNode* root = new TreeNode(postorder[size - 1]);
    if (i == 0) {
      // can use index to avoid copy vector
      auto lvector = vector<int>(begin(inorder) + 1, end(inorder));
      auto rvector = vector<int>(begin(postorder), begin(postorder) + size - 1);
      auto right = buildTree(lvector, rvector);
      root->right = right;
    } else {
      // can use index to avoid copy vector
      auto lvector = vector<int>(begin(inorder), begin(inorder) + i);
      auto rvector = vector<int>(begin(postorder), begin(postorder) + i);
      auto left = buildTree(lvector, rvector);
      auto llvector = vector<int>(begin(inorder) + i + 1, end(inorder));
      auto rrvector =
          vector<int>(begin(postorder) + i, begin(postorder) + size - 1);
      auto right = buildTree(llvector, rrvector);
      root->left = left;
      root->right = right;
    }
    return root;
  }
};
