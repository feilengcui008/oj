#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    int size = strs.size();
    if (size == 0) return string("");
    string &pre = strs[0];
    for (int i = 1; i < size; i++) {
      pre = longest(pre, strs[i]);
      if (pre.length() == 0)  // optimization
        return string("");
    }
    return pre;
  }

  string longest(const string &s1, const string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1 == 0 || len2 == 0) return string("");
    int len = len1 < len2 ? len1 : len2;
    int i;
    for (i = 0; i < len; ++i) {
      if (s1[i] != s2[i]) break;
    }
    return s1.substr(0, i);
  }
};

int main(int argc, char *argv[]) {
  string s1 = "pre";
  string s2 = "present";
  vector<string> v{"pre", "present", "p"};
  Solution s;
  cout << s.longest(s1, s2) << endl;
  cout << s.longestCommonPrefix(v) << endl;
  return 0;
}
