#include <iostream>
#include <vector>

using namespace std;

class Solution {

  public:
    int jump(vector<int> &nums)
    {
      int size = nums.size();
      int currentEnd = 0, nextEnd = 0, jumps = 0;
      for (int i = 0; i < size - 1; ++i) {
        nextEnd = nums[i] + i > nextEnd ? nums[i] + i : nextEnd;
        if (i == currentEnd) {
          currentEnd = nextEnd;
          jumps++;
        }
      }
      return jumps;
    }

    // time: O(n^2), space: O(n)
    // 动态规划
    int jump1(vector<int>& nums)
    {
      int size = nums.size();
      if (size <= 1) return 0;
      // dp[i]表示从0跳到i处需要的最少步数
      vector<int> dp;
      for (int i = 0; i < size; ++i) {
          dp.push_back(i);
      }
      // dp[i] = min{dp[i], dp[k] + 1} 其中 0 <= k < i
      // 注意这样一个事实，dp[i]最短的路径一定是只经过
      // [0, i)的某个点k，且能从k一步到达i的，可以证明
      for (int i = 2; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
          if (nums[j] >= (i - j) && (dp[j] + 1) < dp[i]) {
            dp[i] = dp[j] + 1;
          }
        }
      }
      return dp[size-1];
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  vector<int> v{3, 2, 1};
  vector<int> v1{2, 3, 1, 1, 4};
  cout << s.jump(v) << endl;
  cout << s.jump(v1) << endl;
  return 0;
}
