#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(logn), space: O(1)
  // binary search
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    if (row == 0) return false;
    int col = matrix[0].size();
    if (col == 0) return false;
    int l = 1, r = row * col, m;
    while (l <= r) {
      m = l + (r - l) / 2;
      int t = getValue(matrix, m);
      if (t == target) {
        return true;
      } else if (t < target) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return false;
  }

  inline int getValue(vector<vector<int>>& matrix, int n) {
    int row = matrix.size();
    int col = matrix[0].size();
    row = (n - 1) / col;
    col = (n - 1) % col;
    return matrix[row][col];
  }
};
