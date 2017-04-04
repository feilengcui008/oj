#include <string>

using namespace std;

class Solution {
  public:
    string reverseString(string s)
    {
      int len = s.length();
      if (len <= 1) return s;
      for (int i = 0; i < (len / 2); ++i) {
        char c = s[len - 1 - i];
        s[len - 1 - i] = s[i];
        s[i] = c; 
      }
      return s;
    }
};
