#include <string>

using namespace std;

class Solution {
  public:
    string reverseVowels(string s) 
    {
      int len = s.length();
      if (len <= 1) return s;
      int i = 0;
      int j = len - 1;
      while (i < j) {
        while (i < j && !isVowel(s[i])) i++;
        while (i < j && !isVowel(s[j])) j--;
        if (i < j) {
          char c = s[i];
          s[i] = s[j];
          s[j] = c;
          i++; j--;
        }
      }
      return s;
    }

    bool isVowel(char c)
    {
      return c == 'a' || c == 'o' || c == 'u' || c == 'e' || c == 'i'
        || c == 'A' || c == 'O' || c == 'U' || c == 'E' || c == 'I';
    }
};
