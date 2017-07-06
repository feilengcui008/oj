#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

 public:
  // time: O(n!), space: O(n^2)
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> v;
    vector<bool> status(nums.size(), false);
    nextElement(nums, res, v, status, 0);
    return res;
  }

  void nextElement(vector<int> &nums, vector<vector<int>> &res, vector<int> &v,
                   vector<bool> &status, int l) {
    int size = nums.size();
    if (l == size) res.emplace_back(std::move(v));
    unordered_map<int, bool> um;
    for (int i = 0; i < size; ++i) {
      if (!status[i] && um.find(nums[i]) == um.end()) {
        um[nums[i]] = true;
        auto v1 = v;
        v1.push_back(nums[i]);
        status[i] = true;
        nextElement(nums, res, v1, status, l + 1);
        status[i] = false;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  vector<int> v{1, 1, 2, 3, 4};
  Solution s;
  auto res = s.permuteUnique(v);
  for (auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}
