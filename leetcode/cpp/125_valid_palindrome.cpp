#include <string>
#include <iostream>

using namespace std;


class Solution {
  public:
    bool isPalindrome(string s) 
    {
      int len = s.length();
      int i, j;
      if (len <= 1)
        return true;
      if (len == 2) 
        return !(isAlphanumeric(s[0]) && isAlphanumeric(s[1]) 
            && !charEqual(s[0], s[1]));
      i = 0; j = len -1;
      while (i < j) {
        if (!isAlphanumeric(s[i])) {
          i++;
          continue;
        }
        if (!isAlphanumeric(s[j])) {
          j--;
          continue;
        }
        if (!charEqual(s[i], s[j])) {
          break;
        } else {
          i++; j--;
        }
      }
      if (i == j) return true;
      if (charEqual(s[i], s[j])) return true;
      if (!isAlphanumeric(s[i]) && !isAlphanumeric(s[j])) 
        return true;
      return false;
    }

    bool isAlphanumeric(char c) 
    { 
      return (c >= '0' && c <= '9') 
        || (c >= 'A' && c <= 'Z') 
        || (c >= 'a' && c <= 'z');
    }

    bool isAlpha(char c) 
    {
      return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    bool charEqual(char c1, char c2) 
    {
      return (c1 == c2) || 
        (isAlpha(c1) && isAlpha(c2) && 
         ((c1 == c2 + 'A' - 'a') || (c1 == c2 - 'A' + 'a')));
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  string s1 = "A man, a plan, a canal: Panama";
  string s2 = "";
  string s3 = "a";
  string s4 = "race a car";
  string s5 = "0P";
  cout << s.isPalindrome(s1) << endl;
  cout << s.isPalindrome(s2) << endl;
  cout << s.isPalindrome(s3) << endl;
  cout << s.isPalindrome(s4) << endl;
  cout << s.isPalindrome(s5) << endl;
  return 0;
}
