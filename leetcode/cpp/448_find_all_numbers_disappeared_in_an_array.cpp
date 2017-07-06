#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  // time: O(n), space: O(1)
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> res;
    int size = nums.size();
    // mark
    // also can make the nums[i] = -1 * nums[i]
    // but that way can not check numbers appeared
    // more than 2 times.
    for (int i = 0; i < size; ++i) {
      nums[nums[i] % (size + 1) - 1] += (size + 1);
    }
    // check
    for (int i = 0; i < size; ++i) {
      if (nums[i] < (size + 1)) {
        res.push_back(i + 1);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v{4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> v1{4, 3, 2, 7, 7, 2, 3, 1};
  Solution s;
  auto res = s.findDisappearedNumbers(v);
  auto res1 = s.findDisappearedNumbers(v1);
  for (const auto &ele : res) {
    cout << ele << endl;
  }
  cout << "------" << endl;
  for (auto ele : res1) {
    cout << ele << endl;
  }
  return 0;
}
