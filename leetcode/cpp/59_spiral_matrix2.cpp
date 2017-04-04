#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n)
    {
      vector<vector<int>> res;
      for (int i = 0; i < n; ++i) {
        res.push_back(vector<int>(n, -1));
      }
      int k = 0, idx = 1;
      while (k < n) {
        if (k == n - 1) {
          res[n / 2][n / 2] = idx;
          break;
        }
        for (int i = k / 2; i < (n - 1 - k / 2); ++i) {
          res[k / 2][i] = idx;
          idx++;  
        }
        for (int j = k / 2; j < (n - 1 - k / 2); ++j) {
          res[j][n - 1 - k / 2] = idx;
          idx++;
        }
        for (int i = n - 1 - k / 2; i > k / 2; i--) {
          res[n - 1 - k / 2][i] = idx;
          idx++;
        }
        for (int j = n - 1 - k / 2; j > k / 2; j--) {
          res[j][k / 2] = idx;
          idx++;
        }
        k += 2;
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  auto res = s.generateMatrix(8);
  for (auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}
