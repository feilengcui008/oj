#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    bool isMatch(string s, string p) 
    {
      return matchHere(s, p, 0, 0);
    }

    // each call to matchHere will consume at least one sub pattern
    // which is one of '.', 'letter*', 'letter', we look ahead one 
    // char for handling 'letter*' sub pattern
    bool matchHere(string s, string re, int index1, int index2) 
    {
      int l1 = s.size(), l2 = re.size();
      if (index1 >= l1 && index2 >= l2) {
        return true;
      }

      // only left one char in regex string
      if (index2 + 1 == l2) {
        if (index1 + 1 != l1) return false;
        if (re[index2] == '.' || re[index2] == '*') return true;
        return s[index1] == re[index2]; 
      }

      // 'letter' or '.' sub pattern
      if (index2 + 1 < l2 && re[index2 + 1] != '*') {
        if (index1 >= l1) return false;  // notice here
        // '.' sub pattern
        if (re[index2] == '.') {
          return matchHere(s, re, index1 + 1, index2 + 1);
        }
        // 'letter' sub pattern
        if (re[index2] != '.' && re[index2] != '*') {
          if (s[index1] != re[index2]) return false;
          return matchHere(s, re, index1 + 1, index2 + 1);
        }
      } 
      // 'letter*' or '.*' sub pattern
      if (index2 + 1 < l2 && re[index2 + 1] == '*') {
        if (index1 >= l1) return matchHere(s, re, index1, index2 + 2);  // notice here
        // 'letter*' sub pattern
        if (re[index2] != '.' && re[index2] != '*') {
          if (s[index1] != re[index2]) {
            return matchHere(s, re, index1, index2 + 2);
          } else {
            // note we need consider case like a*a, so we need 
            // check all possible branches
            int count = 0, k = index1;
            while (k < (int)s.size() && s[k] == s[index1]) {
              count++, k++;
            }
            bool res = false;
            // this may not be very efficient...
            for (int j = 0; j <= count; ++j) {
              res |= matchHere(s, re, index1 + j, index2 + 2);
            }
            return res;
          }
        } else {  // '.*' sub pattern
          bool res = false;
          // need check all possible branches
          for (int j = 0; j <= (int)s.size() - index1; ++j) {
            res |= matchHere(s, re, index1 + j, index2 + 2);
          }
          return res;
        }
      } 
      return false;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << boolalpha;
  cout << s.isMatch("aa", "a") << endl;
  cout << s.isMatch("aa", "a*") << endl;
  cout << s.isMatch("aa", ".*") << endl;
  cout << s.isMatch("ab", ".*") << endl;
  cout << s.isMatch("aab", "c*a*b") << endl;
  cout << s.isMatch("aaa", "a*a") << endl;
  cout << s.isMatch("aaa", "ab*a*c*a") << endl;
  cout << s.isMatch("aaba", "ab*a*c*a") << endl;
  cout << s.isMatch("a", "ab*") << endl;
  return 0;
}
