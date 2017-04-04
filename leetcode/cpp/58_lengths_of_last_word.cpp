#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    int lengthOfLastWord(string s) 
    {
      int res = 0;
      int len = s.length();
      // find the first non blank pos
      int i; 
      for (i = len -1; i >= 0; --i) {
        if (s[i] != ' ') break; 
      }
      if (i == -1) return res;
      while (i >= 0) {
        if (s[i] == ' ') break;
        res++;
        i--;
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
  string s1("fa ");
  Solution s;
  cout << s.lengthOfLastWord(s1) << endl;
  return 0;
}
