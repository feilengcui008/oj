#include <vector>

using namespace std;

class Solution {
  public:
    // time: O(n), space: O(n)
    // dp or fibonachi: dp[i] = dp[i-1] + dp[i-2]
    int climbStairs(int n)
    {
      vector<int> dp(n+1, -1);
      dp[0] = 1; dp[1] = 1;
      for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
      }
      return dp[n];
    }
};
