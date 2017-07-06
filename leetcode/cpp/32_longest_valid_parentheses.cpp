#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  // time: O(n), space: O(n)
  int longestValidParentheses(string s) {
    stack<int> st;
    int len = s.length();
    if (len <= 1) return 0;
    for (int i = 0; i < len; ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        if (!st.empty() && s[st.top()] == '(') {
          st.pop();
        } else {
          st.push(i);
        }
      }
    }
    if (st.empty()) return len;
    int max = 0, pre = len, t;
    while (!st.empty()) {
      t = st.top();
      st.pop();
      if (pre - t - 1 > max) max = pre - t - 1;
      pre = t;
    }
    if (pre > max) max = pre;
    return max;
  }

  // dynamic programming
  // time: O(n), space: O(1)
  // longest[i] =
  //   longest[i-1]  if s[i] == '('
  //   longest[i-2]+2  if s[i-1] == '('
  //   longest[i-1]+2+longest[i-longest[i-1]-2] if s[i-longest[i-1]-1] == '(' &&
  // s[i-1] == ')'
  int longestValidParentheses1(string s) {
    int len = s.length();
    if (len <= 1) return 0;
    if (len == 2) {
      if (s[0] == '(' && s[1] == ')') return 2;
      return 0;
    }
    vector<int> longest(len, 0);
    longest[0] = 0;
    longest[1] = (s[0] == '(' && s[1] == ')') ? 2 : 0;
    for (int i = 2; i < len; ++i) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          longest[i] = longest[i - 2] + 2;
        } else {
          if (i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(') {
            longest[i] = longest[i - 1] + 2 + longest[i - longest[i - 1] - 2];
          }
        }
      }
    }
    return *max_element(begin(longest), end(longest));
  }

  // naive solution
  // time: O(n^3), space: O(n)
  int longestValidParentheses2(string s) {
    int l = s.length();
    int m = 0;
    for (int i = 0; i < l; ++i) {
      if (s[i] == ')') continue;
      for (int j = i + 1; j < l; ++j) {
        if (s[j] == '(') continue;
        if (isValid(s.substr(i, j - i + 1)) && (j - i + 1) > m) m = j - i + 1;
      }
    }
    return m;
  }

  bool isValid(string s) {
    stack<char> st;
    int len = s.length();
    // corner case
    if (len == 0) return true;
    for (int i = 0; i < len; ++i) {
      switch (s[i]) {
        case '(':
        case '{':
        case '[':
          st.push(s[i]);
          break;
        case ')':
        case '}':
        case ']':
          if (st.empty()) return false;
          char c = st.top();
          st.pop();
          if ((s[i] == ')' && c != '(') || (s[i] == '}' && c != '{') ||
              (s[i] == ']' && c != '[')) {
            return false;
          }
      }
    }
    if (!st.empty()) return false;
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string s1 = ")()())";
  cout << s.longestValidParentheses1(s1) << endl;
  cout << s.longestValidParentheses1("()") << endl;
  cout << s.longestValidParentheses1("()(()") << endl;
  return 0;
}
