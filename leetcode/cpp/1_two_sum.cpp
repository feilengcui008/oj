#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <array>

using namespace std;

class Solution {
  public:
    //use unordered_map.find
    vector<int> twoSum1(vector<int>& nums, int target) 
    {
      int size = nums.size();
      unordered_map<int, int> um;
      for (int i = 0; i < size; i++) {
        if (um.find(target - nums[i]) != um.end()) {
          return vector<int>{um[target - nums[i]] + 1, i + 1};
        } else {
          um[nums[i]] = i;
        }
      }
      return vector<int>();

    }

    //use unordered_map.find all pairs
    vector<vector<int>> twoSum11(vector<int>& nums, int target) 
    {
      int size = nums.size();
      vector<vector<int>> vv;
      unordered_map<int, int> um;
      for (int i = 0; i < size; i++) {
        if (um.find(target - nums[i]) != um.end()) {
          vv.push_back(vector<int>{um[target - nums[i]] + 1, i + 1});
        } else {
          um[nums[i]] = i;
        }
      }
      return vv;
    }

    //use space for unordered_map.find,but it seems not so good
    vector<int> twoSum2(vector<int>& nums, int target) 
    {
      int size = nums.size();
      unordered_map<int, int> um;
      unordered_map<int, int> um1;
      for (const auto &ele : nums) {
        um[ele] = -1;
        um1[target - ele] = -2;
      }
      for (const auto &ele : nums) {
        um1[ele] = 1;
      }
      for (int i = 0; i < size; i++) {
        if (um[target - nums[i]] != -1 && um1[target - nums[i]] == 1) {
          return vector<int>{um[target - nums[i]] + 1, i + 1};
        } else {
          um[nums[i]] = i;
        }
      }
      return vector<int>{};
    }

    // o(nlogn) can not get the same original index,just get the two numbers
    vector<int> twoSum3(vector<int>& nums, int target) 
    {
      sort(nums.begin(), nums.end());
      int i = 0, j = nums.size() - 1;
      while (i != j) {
        if (nums[i] + nums[j] == target)
          break;
        else if (nums[i] + nums[j] < target)
          i++;
        else
          j--;
      }
      return vector<int> {nums[i], nums[j]};
    }
};

int main(int argc, char *argv[])
{
  auto v = vector<int>{-3, 4, 3, -4, 1,-1, 90};
  Solution s;
  auto v1 = s.twoSum1(v, 0);
  auto v2 = s.twoSum11(v, 0);
  auto v3 = s.twoSum3(v, 0);
  cout << "use unordered_map.find,return one pair:\n";
  for (const auto &ele : v1) {
    cout << ele << "\t";
  }
  cout << endl;

  cout << "use unordered_map.find all pairs:\n";
  for (const auto &ele : v2) {
    for (const auto &ele1 : ele) {
      cout << ele1 << "\t";
    }
    cout << endl;
  }
  cout << endl;

  cout << "use sort first method:" << endl;
  for (const auto &ele : v3) {
    cout << ele << endl;
  }
  cout << endl;
  return 0;
}
