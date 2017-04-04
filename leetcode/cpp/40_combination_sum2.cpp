#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {

  public:
    // time: O(n^3), space: O(n)
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
      // sort fisrt
      sort(candidates.begin(), candidates.end());
      vector<vector<int>> res;
      vector<int> v;
      innerSum(res, candidates, v, candidates.size() - 1, target);
      return res;
    }

    void innerSum(vector<vector<int>> &res, vector<int> &candidates, vector<int> &v, int r, int target)
    {
      // stop condition
      if (target == 0) {
        sort(v.begin(), v.end());
        bool flag = false;
        for (auto &ele : res) {
          int i = 0;
          for (; i < (int)v.size(); ++i) {
            if (ele[i] != v[i]) break;
          }
          if (i == (int)v.size()) {
            flag = true;
            break;
          }
        }
        if (!flag) {
          res.push_back(v);
        }
        return;
      }
      if (r < 0) return;
      if (candidates[0] > target) return; 

      int c = target / candidates[r];
      innerSum(res, candidates, v, r - 1, target);
      if (c > 0) {
        vector<int> t = v;
        t.push_back(candidates[r]);
        innerSum(res, candidates, t, r - 1, target - candidates[r]);
      }

    }
};


int main(int argc, char *argv[])
{
  vector<int> v{10, 1, 2, 7, 6, 1, 5};
  vector<int> v1{8, 7, 4, 3};
  Solution s;
  auto res = s.combinationSum2(v, 8);
  for (const auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  cout << "=======\n";
  res = s.combinationSum2(v1, 11);
  for (const auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}
