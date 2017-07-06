#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
  // time exceed...
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    res.clear();
    vector<bool> status(n, false);
    vector<int> temp(1, 0);
    innerCombination(res, 0, temp, status, k, n);
    return res;
  }

  // 优先考虑递归的方法解决序列生成的问题
  void innerCombination(vector<vector<int>> &res, int currentIndex,
                        vector<int> temp, vector<bool> status, int k, int n,
                        int begin = 1, int end = 9) {
    // O(n)
    // for_each(temp.begin(), temp.end(), [&sum](int x) -> void { sum += x; });

    // optimization
    int sum = temp[temp.size() - 1];
    if (sum > n) return;
    // stop condition
    if (currentIndex == k) {
      if (sum == n) {
        // pop out sum at the end of temp
        temp.pop_back();
        // O(n * log(n))
        sort(temp.begin(), temp.end());
        // O(n^2)
        if (find(res.begin(), res.end(), temp) == res.end()) {
          res.push_back(temp);
        }
      }
      return;
    }
    // find next valid number
    // O(n)
    for (int i = begin; i <= end; ++i) {
      if (sum + i <= n && status[i - begin] == false) {
        vector<int> newvector = temp;
        vector<bool> newstatus = status;
        newvector.insert(newvector.begin(), i);
        // update sum
        newvector[newvector.size() - 1] += i;
        newstatus[i - begin] = true;
        innerCombination(res, currentIndex + 1, newvector, newstatus, k, n,
                         begin, end);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  // auto res = s.combinationSum3(3, 7);
  auto res = s.combinationSum3(8, 36);
  for (auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}
