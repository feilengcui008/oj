#include <string>
#include <iostream>

using namespace std;
class Solution {
  public:
    // maybe change to o(n)?
    string longestPalindrome(string s)
    {
      return naiveLongestPalindrome(s);
    }

    // o(n^2),spread to two direction from each element
    string naiveLongestPalindrome(string s)
    {
      // length <= 1
      if (s.length() <= 1)
        return s;

      int pos, len, max;
      int i, j, k;
      string res = "";
      pos = 0;  // first
      len = 1;
      max = 1;
      int size = s.length();  // at least 2
      for (i=0; i < size-1; i++) {
        // ok, spread to two directions 
        len = 1;
        j = i - 1;
        k = i + 1;
        while (j >= 0 && k < size && (s[j--] == s[k++]))
          len += 2;
        if (len > max) {
          max = len;
          pos = i;
        }

        // we need recheck if s[i+1]==s[i]
        if (s[i+1] == s[i]) {
          len = 0;
          j = i;
          k = i + 1;
          while (j >= 0 && k < size && (s[j--] == s[k++]))
            len += 2;
          if (len > max) {
            max = len;
            pos = i;
          }
        }
      }
      int start = 0;
      if (max % 2 == 0)
        start = pos + 1 - max / 2;
      else
        start = pos - max / 2; 
      res = s.substr(start, max);
      return res;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  std::cout << s.naiveLongestPalindrome("12321") << "\n";
  std::cout << s.naiveLongestPalindrome("1232") << "\n";
  std::cout << s.naiveLongestPalindrome("1") << "\n";
  std::cout << s.naiveLongestPalindrome("11") << "\n";
  std::cout << s.naiveLongestPalindrome("512218") << "\n";
  std::cout << s.naiveLongestPalindrome("2218") << "\n";
  std::cout << s.naiveLongestPalindrome("aaaa") << "\n";
  std::cout << s.naiveLongestPalindrome("aaaaa") << "\n";
  return 0;
}
