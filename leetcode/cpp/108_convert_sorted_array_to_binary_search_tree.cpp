#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(logn*n), space: O(logn*n)
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int size = nums.size(), middle = size / 2;
    if (size == 0) return nullptr;
    if (size == 1) return new TreeNode(nums[0]);
    TreeNode* root = new TreeNode(nums[middle]);
    // can avoid copy vector by using index
    auto lvector = vector<int>(begin(nums), begin(nums) + middle);
    auto rvector = vector<int>(begin(nums) + middle + 1, end(nums));
    root->left = sortedArrayToBST(lvector);
    root->right = sortedArrayToBST(rvector);
    return root;
  }
};
