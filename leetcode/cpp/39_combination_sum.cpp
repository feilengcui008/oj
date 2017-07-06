#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

 public:
  // time: O(n*{target/candidates[0]}), space: O(n)
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    // sort fisrt
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> v;
    innerSum(res, candidates, v, candidates.size() - 1, target);
    return res;
  }

  void innerSum(vector<vector<int>> &res, vector<int> &candidates,
                vector<int> &v, int r, int target) {
    // stop condition
    if (target == 0) {
      res.push_back(v);
      return;
    }
    if (r < 0) return;
    if (candidates[0] > target) return;

    int c = target / candidates[r];
    innerSum(res, candidates, v, r - 1, target);
    for (int i = 0; i < c; ++i) {
      vector<int> t = v;
      for (int j = 0; j < i + 1; ++j) {
        t.push_back(candidates[r]);
      }
      innerSum(res, candidates, t, r - 1, target - (i + 1) * candidates[r]);
    }
  }
};

int main(int argc, char *argv[]) {
  vector<int> v{2, 3, 6, 7};
  vector<int> v1{8, 7, 4, 3};
  Solution s;
  auto res = s.combinationSum(v, 7);
  for (const auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  cout << "=======\n";
  res = s.combinationSum(v1, 11);
  for (const auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}
