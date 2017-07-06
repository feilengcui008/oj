#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(m*n), space: O(m*n)
  // 二维动态规划，注意这里有个处理下标
  // 小于0的技巧，让状态空间的维数都增加
  // 一维，并初始化看似无意义的dp[0][k]和
  // dp[k][0].
  bool isMatch(string s, string p) {
    int l1 = s.length(), l2 = p.length();
    vector<vector<bool>> dp;
    // dp[i][j]中i, 分别表示s前i个字符和
    // p中前j个字符的匹配情况
    for (int i = 0; i <= l1; ++i) {
      vector<bool> v(l2 + 1, false);
      dp.emplace_back(move(v));
    }
    dp[0][0] = true;
    for (int i = 0; i < l2; ++i) {
      if (p[i] != '*') break;
      dp[0][i + 1] = true;
    }

    for (int i = 1; i <= l1; ++i) {
      for (int j = 1; j <= l2; ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
        } else {
          if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
          }
        }
      }
    }
    return dp[l1][l2];
  }

  // time: O(m*n), space: O(n)
  // 二维动规，注意上面在迭代填表的时候，
  // 实际上对于每个模式的字符，都有一个
  // 匹配数组与之对应，如果我们能在迭代
  // 填表的过程中重复利用这个数组，则可
  // 节省空间。
  bool isMatch1(string s, string p) {
    int m = s.length(), n = p.length();
    // cur[i]表示在匹配前k([1, n])个模式字符的时候，
    // 当时s中前i个字符是否与之匹配。
    vector<bool> cur(false, m + 1);
    cur[0] = true;
    // 匹配前i个模式字符
    for (int i = 1; i <= n; ++i) {
      // 先记录上一次的cur[0]
      // 只有模式串前i个全是'*'，才能匹配空串
      bool pre = cur[0];
      cur[0] = cur[0] && p[i - 1] == '*';
      // s前j个字符是否与前i个模式字符匹配(填表)
      for (int j = 1; j <= m; ++j) {
        bool t = cur[i];  // 保存到下一轮使用
        if (p[i - 1] == '*') {
          cur[j] = cur[j] | cur[j - 1];
        } else {
          // 这种情况要用到上一轮的cur[j-1]，所以
          // 需要用pre保存
          if (s[j - 1] == p[i - 1] || p[i - 1] == '?') {
            cur[j] = pre;
          }
          pre = t;
        }
      }
    }
    return cur[n];
  }

  // TLE...
  bool isMatch2(string s, string p) { return matchHere(s, p, 0, 0); }

  bool matchHere(const string &s, const string &re, int index1, int index2) {
    int l1 = s.size(), l2 = re.size();
    if (index1 >= l1 && index2 >= l2) {
      return true;
    }
    if (index2 >= l2) return false;
    if (index1 >= l1) {
      while (re[index2] == '*' && index2 < l2) index2++;
      if (index2 == l2) return true;
      return false;
    }
    // ok, both index1 and index2 are normal conditions
    if (re[index2] != '*') {
      return (re[index2] == '?' && matchHere(s, re, index1 + 1, index2 + 1)) ||
             (re[index2] == s[index1] &&
              matchHere(s, re, index1 + 1, index2 + 1));
    } else {
      // count how many * we can skip
      int c = 0, t = index2;
      while (re[t] == '*' && t < l2) {
        c++;
        t++;
      }
      // skip index1 for any times
      int left = l1 - index1;
      bool res = false;
      for (int k = left; k >= 0; --k) {
        res |= matchHere(s, re, index1 + k, index2 + c);
        if (res == true) return res;
      }
      return false;
    }
    return false;
  }

  // 这个答案实际上和isMatch2中的递归是类似的
  bool isMatch3(const char *s, const char *p) {
    const char *star = NULL;
    const char *ss = s;
    while (*s) {
      // advancing both pointers when (both characters match) or ('?' found in
      // pattern)
      // note that *p will not advance beyond its length
      if ((*p == '?') || (*p == *s)) {
        s++;
        p++;
        continue;
      }
      // * found in pattern, track index of *, only advancing pattern pointer
      if (*p == '*') {
        star = p++;
        ss = s;
        continue;
      }
      // current characters didn't match, last pattern pointer was *, current
      // pattern pointer is not *
      // only advancing pattern pointer
      if (star) {
        p = star + 1;
        s = ++ss;
        continue;
      }
      // current pattern pointer is not star, last patter pointer was not *
      // characters do not match
      return false;
    }
    // check for remaining characters in pattern
    while (*p == '*') {
      p++;
    }
    return !*p;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << boolalpha;
  cout << s.isMatch("aa", "a") << endl;
  cout << s.isMatch("aa", "aa") << endl;
  cout << s.isMatch("aaa", "aa") << endl;
  cout << s.isMatch("aa", "*") << endl;
  cout << s.isMatch("aa", "a*") << endl;
  cout << s.isMatch("ab", "?*") << endl;
  cout << s.isMatch("aab", "c*a*b") << endl;
  cout << s.isMatch("", "?") << endl;
  string s1 = "abbaaaabbbbbababbbbbbbbaaabaabbabaabbaaabbbbabbbbab";
  string p1 = "a*aaba***b**a*a********b";
  cout << s.isMatch(s1, p1) << endl;
  return 0;
}
