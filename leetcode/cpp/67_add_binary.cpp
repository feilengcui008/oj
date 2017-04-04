#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
      int len1 = a.length();
      int len2 = b.length();
      if (len1 == 0 || len2 == 0)
        return a + b;
      if (len1 < len2) 
        return addBinary(b, a);
      bool flag = false; int i;
      int delta = len1 - len2;
      for (i = len1 -1; i >= 0; i--) {
        if (i >= delta) {
          if (flag == true) {
            if (a[i] == '1' && b[i - delta] == '1') {
              a[i] = '1';
              flag = true;
            } else if (a[i] == '0' && b[i - delta] == '0') {
              a[i] = '1';
              flag = false;
            } else {
              a[i] = '0';
              flag = true;
            }
          } else {
            if (a[i] == '1' && b[i - delta] == '1') {
              a[i] = '0';
              flag = true;
            } else if (a[i] == '0' && b[i - delta] == '0') {
              a[i] = '0';
              flag = false;
            } else {
              a[i] = '1';
              flag = false;
            }
          }
          // cout << "---" << a[i] << endl;
          continue;
        }
        // only the part of string a
        if (a[i] == '0' || flag == false)
          break; 
        else {
          a[i] = '0';
          flag = true;
          // cout << "===" << a[i] << endl;
        }
      }

      // after break
      if (flag == true) {
        if (i == -1)
          return "1" + a;
        else a[i] = '1';
      }
      return a;
    }
};


int main(int argc, char *argv[])
{
  Solution s;
  string s1 = "11";
  string s2 = "1";
  string s3 = "111";
  string s4 = "10";
  string s5 = "101111";
  string s6 = "10";
  //cout << s.addBinary(s2, s1) << endl;
  //cout << s.addBinary(s3, s4) << endl;
  cout << s.addBinary(s5, s6) << endl;
  return 0;
}
