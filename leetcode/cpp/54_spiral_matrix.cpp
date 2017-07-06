#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(n*m), space: O(1)
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> res;
    int row = matrix.size();
    if (row == 0) return res;
    int col = matrix[0].size();
    travelLevel(matrix, res, 0, col - 1, 0, row - 1);
    return res;
  }

  void travelLevel(const vector<vector<int>> &matrix, vector<int> &res,
                   int xBegin, int xEnd, int yBegin, int yEnd) {
    if (xBegin > xEnd || yBegin > yEnd) return;
    if (xBegin == xEnd) {
      for (int i = yBegin; i <= yEnd; ++i) {
        res.push_back(matrix[i][xBegin]);
      }
      return;
    }
    if (yBegin == yEnd) {
      for (int i = xBegin; i <= xEnd; ++i) {
        res.push_back(matrix[yBegin][i]);
      }
      return;
    }
    // travel a circle
    for (int i = xBegin; i < xEnd; ++i) {
      res.push_back(matrix[yBegin][i]);
    }
    for (int i = yBegin; i < yEnd; ++i) {
      res.push_back(matrix[i][xEnd]);
    }
    for (int i = xEnd; i > xBegin; i--) {
      res.push_back(matrix[yEnd][i]);
    }
    for (int i = yEnd; i > yBegin; i--) {
      res.push_back(matrix[i][xBegin]);
    }
    travelLevel(matrix, res, xBegin + 1, xEnd - 1, yBegin + 1, yEnd - 1);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> vv{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, };
  Solution s;
  auto res = s.spiralOrder(vv);
  for (auto &ele : res) {
    cout << ele << endl;
  }
  return 0;
}
