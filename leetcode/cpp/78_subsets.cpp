#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
  // time: O(2^n), space: O(n)
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> temp;
    dfs(res, nums, temp, 0);
    return res;
  }

  void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &temp,
           int l) {
    int size = nums.size();
    if (l == size) {
      res.push_back(temp);
      return;
    }
    auto v1 = temp, v2 = temp;
    v1.push_back(nums[l]);
    dfs(res, nums, v1, l + 1);
    dfs(res, nums, v2, l + 1);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v{1, 2, 3};
  auto res = s.subsets(v);
  for (auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}
