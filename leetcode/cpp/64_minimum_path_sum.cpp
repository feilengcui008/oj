#include <vector>
#include <limits>

using namespace std;

class Solution {
  public:
    // time: O(n^2), space: O(n^2)
    // two dimension dp
    // dp[i][j] = min(d[i-1][j], d[i][j-1])
    int minPathSum(vector<vector<int>>& obstacleGrid)
    {
      int row = obstacleGrid.size();
      if (row == 0) return 0;
      int col = obstacleGrid[0].size();
      if (col == 0) return 0;
      vector<vector<int>> dp;
      // init
      for (int i = 0; i < row; ++i) {
        vector<int> v(col, -1);
        dp.emplace_back(move(v));
      }
      int s = 0;
      for (int i = 0; i < col; ++i) {
        s += obstacleGrid[0][i];
        dp[0][i] = s;
      }
      s = 0;
      for (int i = 0; i < row; ++i) {
        s += obstacleGrid[i][0];
        dp[i][0] = s;
      }
      // fill table
      for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
          dp[i][j] = (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]) + obstacleGrid[i][j];
        }
      }
      return dp[row-1][col-1];       
    }
};
