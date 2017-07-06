#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
  // time: O(2^n), space: O(n)
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    dfs(res, temp, 1, 0, n, k);
    return res;
  }

  void dfs(vector<vector<int>> &res, vector<int> &temp, int l, int c, int n,
           int k) {
    if (c == k) {
      res.push_back(temp);
      return;
    }
    if (n - l + 1 < k - c) {
      return;
    }
    if (l > n) {
      return;
    }
    auto v1 = temp, v2 = temp;
    v1.push_back(l);
    dfs(res, v1, l + 1, c + 1, n, k);
    dfs(res, v2, l + 1, c, n, k);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  auto res = s.combine(4, 2);
  for (auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}
