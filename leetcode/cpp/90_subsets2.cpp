#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

  public:
    // time: O(2^n), space: O(n)
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
      vector<vector<int>> res;
      vector<int> temp;
      unordered_map<int, int> um;
      vector<int> v;
      for (auto ele : nums) {
        if (um.find(ele) == um.end()) {
          um[ele] = 1;
          v.push_back(ele);
        } else {
          um[ele]++;
        }
      }
      dfs(res, v, temp, 0, um);
      return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &temp, int l, unordered_map<int, int> &um)
    {
      int size = nums.size();
      if (l == size) {
        res.push_back(temp);
        return;
      }
      for (int i = 0; i <= um[nums[l]]; ++i) {
        auto v1 = temp;
        for (int j = 0; j < i; ++j) {
          v1.push_back(nums[l]);
        } 
        dfs(res, nums, v1, l + 1, um);
      }
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  vector<int> v{1, 2, 3, 3, 3};
  auto res = s.subsetsWithDup(v);
  for (auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}
