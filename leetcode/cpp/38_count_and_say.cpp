#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
  public:
    string countAndSay(int n) 
    {
      if (n <= 0)
        return string("");
      string result = "1";
      if (n == 1)
        return result;
      for (int i = 2; i <= n; ++i) {
        result = genNext(result);
      }
      return result;
    }

    string genNext(string s) 
    {
      string result = "";
      int len = s.length();
      int k = 0;
      char c;
      for (int i = 0; i < len; ++i) {
        c = s[i];
        k = 0;
        while (s[i] == c) {
          i++;
          k++;
        }
        i--;
        result += itoa(k);
        result.push_back(c);
      }
      return result;
    }

    string itoa(int n) 
    {
      string result = "";
      int remain = 0;
      while ((n / 10) != 0) {
        remain = n % 10;
        n = n / 10;
        result.push_back('0' + remain - 0);
      }
      result.push_back('0' + n - 0);
      return string(result.rbegin(), result.rend());
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.genNext("1") << endl;
  cout << s.genNext("11") << endl;
  cout << s.genNext("21") << endl;
  cout << s.genNext("1211") << endl;
  cout << s.genNext("111221") << endl;
  cout << s.countAndSay(2) << endl;
  cout << s.countAndSay(4) << endl;
  return 0;
}
