#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    // time: O(logn), space: O(1)
    vector<int> searchRange(vector<int>& nums, int target)
    {
      if (nums.size() == 0) return vector<int>{-1, -1};
      auto res = innerSearch(nums, target, 0, nums.size() - 1);
      if (res.size() == 0) return vector<int>{-1, -1};
      return res;
    }

    vector<int> innerSearch(vector<int> &nums, int target, int l, int r)
    {
      vector<int> res;
      if (l >= r) {
        if (l == r && nums[l] == target) {
          res.push_back(l);
          res.push_back(l);
        }
        return res;
      }
      int m = (l + r) / 2;
      if (nums[m] < target) {
        return innerSearch(nums, target, m + 1, r);
      } else if (nums[m] > target) {
        return innerSearch(nums, target, l, m - 1);
      } else {
        // nums[m] == target 
        vector<int> left = innerSearch(nums, target, l, m - 1); 
        vector<int> right = innerSearch(nums, target, m + 1, r); 
        // merge
        if (left.size() != 0) {
          res.push_back(left[0]);
        } else {
          res.push_back(m);
        }
        if (right.size() != 0) {
          res.push_back(right[right.size() - 1]);
        } else {
          res.push_back(m);
        }
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
  vector<int> v{5, 7, 7, 8, 8, 10};
  vector<int> v1{5, 7, 7, 8, 8, 10};
  Solution s;
  auto res = s.searchRange(v, 8);
  for (const auto &ele : res) {
    cout << ele << endl;
  }
  cout << endl;
  res = s.searchRange(v, 0);
  for (const auto &ele : res) {
    cout << ele << endl;
  }
  return 0;
}
