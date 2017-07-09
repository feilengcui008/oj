#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(n^2), space: O(n^2)
  int minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size();
    if (row <= 1) return row == 0 ? 0 : triangle[0][0];
    vector<vector<int>> v;
    for (int i = 0; i < row; i++) {
      vector<int> t;
      for (int j = 0; j < row; j++) {
        t.push_back(-1);
      }
      v.emplace_back(t);
    }
    v[0][0] = triangle[0][0];
    for (int i = 1; i < row; i++) {
      // here we can just remember the min value of this layer
      // to reduce space consumption to O(n)
      for (int j = 0; j <= i; j++) {
        if (j == 0) {
          v[i][j] = v[i - 1][j] + triangle[i][j];
        } else if (j == i) {
          v[i][j] = v[i - 1][j - 1] + triangle[i][j];
        } else {
          v[i][j] =
              (v[i - 1][j] < v[i - 1][j - 1] ? v[i - 1][j] : v[i - 1][j - 1]) +
              triangle[i][j];
        }
      }
    }
    int min = v[row - 1][0];
    for (int i = 1; i < row; i++) {
      if (v[row - 1][i] < min) min = v[row - 1][i];
    }
    return min;
  }
};
