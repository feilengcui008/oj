#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

 public:
  // time: O(n^3), space: O(1)
  // like 3 sum, we skip the duplicates for each loop
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int i, j, size = nums.size();
    vector<vector<int>> res;
    for (i = 0; i < size; i++) {
      int sum3 = target - nums[i];
      // find last 3
      for (j = i + 1; j < size; ++j) {
        int sum2 = sum3 - nums[j];
        // find last 2
        int front = j + 1, back = size - 1;
        int frontVal, backVal;
        while (front < back) {
          // found one pair
          frontVal = nums[front];
          backVal = nums[back];
          if (frontVal + backVal == sum2) {
            res.push_back(vector<int>{nums[i], nums[j], frontVal, backVal});
            // skip duplicates front and back
            while (front < back && nums[front] == frontVal) front++;
            while (front < back && nums[back] == backVal) back--;
          } else if (frontVal + backVal < sum2) {
            front++;
          } else {
            back--;
          }
        }
        // skip duplicates j
        while (j + 1 < size && nums[j + 1] == nums[j]) j++;
      }
      // skip duplicates i
      while (i + 1 < size && nums[i + 1] == nums[i]) i++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v{1, 0, -1, 0, -2, 2};
  Solution s;
  auto res = s.fourSum(v, 0);
  for (const auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}
