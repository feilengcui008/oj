#include <string>
#include <iostream>


/*
 * 1 5 10 50 100 500 1000
 * I V X  L  C   D   M
 * 
 * */

using namespace std;

class Solution {
  public:
    string intToRoman(int num)
    {
      // 1 =< num <= 3999 
      string res;
      int c1 = num / 1000, r = num % 1000;
      int c2 = r / 100;
      r = r % 100;
      int c3 = r / 10;
      r = r % 10;
      //cout << c1 << "\t" << c2 << "\t" << c3 << "\t" << r3 << endl;
      // c1
      if (c1 > 0) {
        for (int i = 0; i < c1; ++i) res.push_back('M');
      }
      // c2
      res += handleDigit(c2, 'C', 'D', 'M');
      // c3
      res += handleDigit(c3, 'X', 'L', 'C');
      // r3
      res += handleDigit(r, 'I', 'V', 'X');
      return res;
    }

    string handleDigit(int c, char s, char m, char b)
    {
      string res;
      if (c > 0) {
        if (c > 8) {
          res.push_back(s);
          res.push_back(b);
        } else if (c > 3 && c < 5) {
          res.push_back(s);
          res.push_back(m);
        } else if (c >= 5) {
          res.push_back(m);
          for (int i = 0; i < c - 5; ++i) res.push_back(s); 
        } else {
          for (int i = 0; i < c; ++i) res.push_back(s); 
        }
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.intToRoman(1980) << endl;
  cout << s.intToRoman(1) << endl;
  cout << s.intToRoman(5) << endl;
  cout << s.intToRoman(10) << endl;
  cout << s.intToRoman(50) << endl;
  cout << s.intToRoman(100) << endl;
  cout << s.intToRoman(500) << endl;
  cout << s.intToRoman(1000) << endl;
  return 0;
}
