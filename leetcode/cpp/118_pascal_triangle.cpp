#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> results;
    if (numRows <= 2) {
      if (numRows <= 0) return results;
      results.push_back(vector<int>{1});
      if (numRows == 1) {
        return results;
      }
      results.push_back(vector<int>{1, 1});
      if (numRows == 2) {
        return results;
      }
    }
    results.push_back(vector<int>{1});
    results.push_back(vector<int>{1, 1});
    int i, j;
    for (i = 2; i < numRows; ++i) {
      vector<int> temp;
      temp.push_back(1);
      for (j = 1; j < i; ++j) {
        temp.push_back(results[i - 1][j - 1] + results[i - 1][j]);
      }
      temp.push_back(1);
      results.push_back(temp);
    }
    return results;
  }
};

void printVec(vector<vector<int>> &v) {
  for (auto &ele : v) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  Solution s;
  auto res = s.generate(5);
  printVec(res);
  return 0;
}
