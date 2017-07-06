#include <string>
#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

class Solution {
 public:
  // time: O(m*n), space: O(m*n)
  // dp: dp[i][j]表示被编辑字符串前i个字符和目标
  // 字符串前j个字符串匹配时的最小编辑距离。则得
  // 到dp[i][j]可能有以下几种情况。
  // dp[i][j] = min{
  //   1. word1[i-1] != word2[j-1]
  //       1.1 经过一次替换  dp[i-1][j-1] + 1
  //       1.2 经过一次删除，有两种匹配情况 dp[i-1][j] + 1 or dp[i-1][j-1] + 1
  //       1.3 经过一次插入，有两种匹配情况 dp[i][j-1] + 1 or dp[i-1][j-1] + 1
  //   2. word1[i-1] == word2[j-1]
  //       除了1中的所有可能操作，再加上dp[i-1][j-1]
  // }
  // 注意: 两个字符串的问题，多半可以考虑二维动态规划，有时可以通过一些手段把
  // O(m*n)的空间复杂度降到O(n)
  int minDistance(string word1, string word2) {
    int l1 = word1.length(), l2 = word2.length();
    if (l1 == 0) return l2;
    if (l2 == 0) return l1;
    vector<vector<int>> dp;
    for (int i = 0; i <= l1; ++i) {
      // -1 means infinity
      dp.emplace_back(vector<int>(l2 + 1, -1));
    }
    for (int i = 0; i <= l2; ++i) {
      dp[0][i] = i;
    }
    for (int i = 0; i <= l1; ++i) {
      dp[i][0] = i;
    }
    int t1, t2, t3;
    for (int i = 1; i <= l1; ++i) {
      for (int j = 1; j <= l2; ++j) {
        // replace
        t1 = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1]
                                            : dp[i - 1][j - 1] + 1;
        // delete
        t2 = dp[i - 1][j] < dp[i - 1][j - 1] ? dp[i - 1][j] + 1
                                             : dp[i - 1][j - 1] + 1;
        // insert
        t3 = dp[i][j - 1] < dp[i - 1][j - 1] ? dp[i][j - 1] + 1
                                             : dp[i - 1][j - 1] + 1;
        dp[i][j] = min(t1, t2, t3, INT_MAX);
      }
    }

    return dp[l1][l2];
  }

  // 方法2: 多分支循环(用递归表达)，超时
  int minDistance1(string word1, string word2) {
    int l1 = word1.length(), l2 = word2.length();
    if (l1 == 0) return l2;
    if (l2 == 0) return l1;
    return ithDistance(word1, word2, 0, 0);
  }

  int ithDistance(string word1, string word2, int i, int pre) {
    if (i == (int)word2.length()) {
      return pre + word1.length();
    }

    if (word1.length() == 0) {
      return pre + word2.length() - i;
    }

    int t1 = INT_MAX;
    if (word1[0] == word2[i]) {
      t1 = ithDistance(word1.substr(1, word1.length() - 1), word2, i + 1, pre);
    }
    // replace a char
    int t2 =
        ithDistance(word1.substr(1, word1.length() - 1), word2, i + 1, pre + 1);
    // delete a char
    int t3 =
        ithDistance(word1.substr(1, word1.length() - 1), word2, i, pre + 1);
    // insert a char
    int t4 = ithDistance(word1, word2, i + 1, pre + 1);
    return min(t1, t2, t3, t4);
  }

  inline int min(int a, int b, int c, int d) {
    int t1 = a < b ? a : b;
    int t2 = t1 < c ? t1 : c;
    return t2 < d ? t2 : d;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.minDistance("abc", "aec") << endl;
  cout << s.minDistance("ab", "aec") << endl;
  cout << s.minDistance("park", "spake") << endl;
  cout << s.minDistance("ab", "bc") << endl;
  return 0;
}
