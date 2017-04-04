#include <vector>

using namespace std;

class Solution {
  public:
    // time: O(n^2), space: O(n^2)
    // two dimension dp
    // dp[i][j] = d[i-1][j] + d[i][j-1]
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
      int row = obstacleGrid.size();
      if (row == 0) return 0;
      int col = obstacleGrid[0].size();
      if (col == 0) return 0;
      vector<vector<int>> dp;
      // init
      for (int i = 0; i <= row; ++i) {
        vector<int> v(col+1, 0);
        dp.emplace_back(move(v));
      }
      // fill table
      dp[1][1] = 1;
      for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
          if (obstacleGrid[i-1][j-1] == 1) {
             dp[i][j] = 0;
          } else {
            if (!(i == 1 && j == 1)) {
              dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
          }
        }
      }
      return dp[row][col];       
    }
};
