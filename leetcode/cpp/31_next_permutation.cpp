#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // time: O(n), space: O(1)
    void nextPermutation(vector<int>& nums)
    {
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
        cout << left_target << "\t" << right_target << endl;
        // 4. reverse new child descending sequence to ascending sequence
        reverse(nums.begin() + left_target + 1, nums.end());
      }
    }
};


int main(int argc, char *argv[])
{
  vector<int> v{3, 2, 1};
  vector<int> v1{1, 3, 2};
  vector<int> v2{1, 5, 1};
  Solution s;
  s.nextPermutation(v);
  s.nextPermutation(v1);
  s.nextPermutation(v2);
  for (auto &ele : v) {
    cout << ele << "\t";
  }
  cout << "\n";
  for (auto &ele : v1) {
    cout << ele << "\t";
  }
  cout << "\n";
  for (auto &ele : v2) {
    cout << ele << "\t";
  }
  cout << "\n";
  return 0;
}
