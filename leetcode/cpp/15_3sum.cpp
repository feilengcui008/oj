#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
 public:
  // time: O(n^2), space: O(1)
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    // sort first and use two-index-method
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int i = 0;
    for (; i < size; ++i) {
      int t = -nums[i];
      int front = i + 1, back = size - 1;
      while (front < back) {
        if (nums[front] + nums[back] == t) {
          int first = nums[front], second = nums[back];
          res.push_back(vector<int>{-t, first, second});
          // skip duplicates of second and third elements
          while (front < back && nums[front] == first) front++;
          while (front < back && nums[back] == second) back--;
        } else if (nums[front] + nums[back] > t) {
          back--;
        } else {
          front++;
        }
      }
      // skip duplicates of third elements
      while (i + 1 < size && nums[i + 1] == nums[i]) i++;
    }
    return res;
  }

  bool binarySearch(const vector<int> &v, int i, int j, int t) {
    if (i > j) return false;
    int m;
    while (i < j) {
      m = (i + j) / 2;
      if (v[m] == t) return true;
      if (v[m] > t) j = m - 1;
      if (v[m] < t) i = m + 1;
    }
    return v[i] == t;
  }

  // use method of two sum
  vector<vector<int>> threeSum1(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> res;
    unordered_set<int> flags;
    for (int i = 0; i < size; ++i) {
      if (flags.find(nums[i]) != flags.end()) {
        continue;
      }
      vector<int> temp = twoSum(nums, -nums[i], i);
      for (auto &ele : temp) {
        vector<int> v{ele, nums[i], -(ele + nums[i])};
        sort(v.begin(), v.end());
        if (!checkExist(res, v)) {
          res.push_back(v);
        }
      }
    }
    return res;
  }

  // find first number of all possible two sum pairs
  vector<int> twoSum(vector<int> &nums, int target, int neg_index) {
    int size = nums.size();
    vector<int> v;
    unordered_map<int, int> um;
    for (int i = 0; i < size && i != neg_index; i++) {
      if (um.find(target - nums[i]) != um.end()) {
        v.push_back(nums[i]);
      } else {
        um[nums[i]] = i;
      }
    }
    return v;
  }

  bool checkExist(const vector<vector<int>> &vv, const vector<int> &v) {
    for (auto &ele : vv) {
      if (ele == v) return true;
    }
    return false;
  }
};

int main(int argc, char **argv) {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<int> nums1 = {1, -1, -1, 0};
  Solution s;
  auto vv = s.threeSum(nums);
  for (auto &ele : vv) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  cout << "\n";
  vv = s.threeSum(nums1);
  for (auto &ele : vv) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
}
