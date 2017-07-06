#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

 public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    int64_t n = 1, size = nums.size();
    for (int i = 1; i <= size; ++i) {
      n *= i;
    }
    res.push_back(nums);
    for (int64_t i = 0; i < n - 1; ++i) {
      nextPermutation(nums);
      res.push_back(nums);
    }
    return res;
  }

  // time: O(n), space: O(1)
  void nextPermutation(vector<int> &nums) {
    int size = nums.size();
    // 1. find the tail descending sequence
    int index = size - 1;
    while (index > 0) {
      if (nums[index] > nums[index - 1]) {
        break;
      }
      index--;
    }
    // special case
    if (index == 0) {
      reverse(nums.begin(), nums.end());
    } else {
      int left_target = index - 1;
      int right_target = size - 1;
      // 2. find first bigger than left_target
      while (right_target >= index && nums[right_target] <= nums[left_target]) {
        right_target--;
      }
      // 3. exchange left and right target
      swap(nums[left_target], nums[right_target]);
      // 4. reverse new child descending sequence to ascending sequence
      reverse(nums.begin() + left_target + 1, nums.end());
    }
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums{1, 2, 3};
  Solution s;
  auto res = s.permute(nums);
  for (auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << "\n";
  }
  return 0;
}
