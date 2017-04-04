#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    unordered_map<int, int> um;
    int numDecodings(string s) 
    {
      um.clear();
      if (s.length() == 0)
        return 0;
      return decode(s, 0);
    }

    int decode(string &s, int index) 
    {
      if (um[index] != 0)
        return um[index];
      if (index < (int)s.length()  && s[index] == '0') {
        um[index] = 0;
        return 0;
      }
      if (index >= (int)s.length() - 1)
        return 1;

      if (s[index] == '1') {
        int temp = decode(s, index + 1) + decode(s, index + 2);
        um[index] = temp;
        return temp; 
      }
      if (s[index] == '2') {
        if (s[index + 1] >= '0' && s[index + 1] <= '6') {
          int temp = decode(s, index + 1) + decode(s, index + 2);
          um[index] = temp;
          return temp; 
        } else {
          int temp = decode(s, index + 1);
          um[index] = temp;
          return temp;
        }
      }
      int temp = decode(s, index + 1);
      um[index] = temp;
      return temp;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  string s1 = "11";
  cout << s.decode(s1, 0) << endl;
  cout << s.numDecodings(s1) << endl;
  return 0;
}
