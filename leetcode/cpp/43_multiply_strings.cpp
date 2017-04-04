#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string multiply(string num1, string num2) 
    {
      string res("0");
      int len1 = num1.size();
      int len2 = num2.size();
      if (len1 == 0 || len2 == 0) return res;
      // preprocessing the number strings
      int begin1, end1; bool flag1 = true;
      int begin2, end2; bool flag2 = true;
      for (begin1 = 0; begin1 < len1; ++begin1) {
        if (num1[begin1] == '-') flag1 = false;
        if (::isdigit(num1[begin1]) && num1[begin1] != '0')
          break;
      }
      for (end1 = len1 - 1; end1 >= begin1; --end1) {
        if (::isdigit(num1[end1])) break;
      }
      if (end1 < begin1) return res;

      for (begin2 = 0; begin2 < len2; ++begin2) {
        if (num2[begin2] == '-') flag2 = false;
        if (::isdigit(num2[begin2]) && num2[begin2] != '0')
          break;
      }
      for (end2 = len2 - 1; end2 >= begin2; --end2) {
        if (::isdigit(num2[end2])) break;
      }
      if (end2 < begin2) return res;

      // ok, can do the multiply 
      int newlen1 = end1 - begin1 + 1;
      int newlen2 = end2 - begin2 + 1;
      int total_len = newlen1 + newlen2;
      res = string(total_len, '0');
      int c = 0;
      int remain = 0;
      int temp = 0;
      int i, j;
      for (i = end1; i >= begin1; --i) {
        for (j = end2; j >= begin2; --j) {
          temp = (num2[j] - '0') * (num1[i] - '0') + res[end2 - j + end1 - i] - '0' + c;
          c = temp / 10;
          remain = temp % 10;
          res[end2 - j + end1 - i] = remain + '0';
        }
        if (c != 0) {
          // 注意不是end2 -j + end1 - i + 1, 由于--j
          res[end2 - j + end1 - i] = c + '0';
        }
        c = 0;
      }
      // return the string 
      reverse(res.begin(), res.end());
      auto ele = res.begin();
      while (ele != res.end() && (*ele) == '0') 
        ele++;
      if (flag1 == flag2) 
        return string(ele, res.end());
      return "-" + string(ele, res.end());
    }
};


int main(int argc, char *argv[])
{
  Solution s;
  string s1 = "123";
  string s2 = "456";
  string s3 = "-12";
  string s4 = "0012";
  string s5 = "9";
  string s6 = "9";
  string s7 = "0";
  string s8 = "1";
  cout << s.multiply(s1, s2) << endl;
  cout << "=====" << endl;
  cout << s.multiply(s3, s4) << endl;
  cout << "=====" << endl;
  cout << s.multiply(s5, s6) << endl;
  cout << "=====" << endl;
  cout << s.multiply(s7, s8) << endl;
  return 0;
}
