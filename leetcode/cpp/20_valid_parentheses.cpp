#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
 public:
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
  string s1 = "(1)";
  string s2 = "[)]";
  string s3 = "()[]{}";
  string s4 = "([)]";
  cout << s.isValid(s1) << endl;
  cout << s.isValid(s2) << endl;
  cout << s.isValid(s3) << endl;
  cout << s.isValid(s4) << endl;
  return 0;
}
