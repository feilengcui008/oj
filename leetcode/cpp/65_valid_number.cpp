#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  // time: O(n), space: O(n)
  bool isNumber(string s) {
    int size = s.length();
    bool dot = false, e = false;
    // basic form: [digits...][.][digits...][e|E][digits...]
    int i = 0;
    // skip head space
    while (i < size && s[i] == ' ') i++;
    if (i == size) return false;
    // skip '-'
    if (s[i] == '-' || s[i] == '+') i++;

    // 1. match first part digits
    string digits1 = "", digits2 = "", digits3 = "";
    while (i < size && isDigit(s[i])) {
      digits1.push_back(s[i]);
      i++;
    }

    // 2. match dot or e|E
    if (i < size && (s[i] != '.' && s[i] != 'e' && s[i] != 'E')) {
      goto End;
    }
    // 2.1 dot
    if (i < size && s[i] == '.') {
      dot = true;
      i++;
      while (i < size && isDigit(s[i])) {
        digits2.push_back(s[i]);
        i++;
      }
      if (digits1.length() == 0 && digits2.length() == 0) return false;
    }
    // 2.2 e or E
    if (i < size && (s[i] == 'e' || s[i] == 'E')) {
      e = true;
      i++;
      if (i < size && (s[i] == '+' || s[i] == '-')) i++;
      while (i < size && isDigit(s[i])) {
        digits3.push_back(s[i]);
        i++;
      }
      // if (digits3.length() == 0 || (dot && digits2.length() == 0) ||
      //    (!dot && digits1.length() == 0)) return false;
      if (digits3.length() == 0 || (!dot && digits1.length() == 0))
        return false;
    }
  End:
    // last check all space
    while (i < size && s[i] == ' ') i++;
    return i == size;
  }

  inline bool isDigit(char c) { return c >= '0' && c <= '9'; }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.isNumber("0") << endl;
  cout << s.isNumber(" 0.1 ") << endl;
  cout << s.isNumber("abc") << endl;
  cout << s.isNumber("1 a") << endl;
  cout << s.isNumber("2e10") << endl;
  cout << s.isNumber(" ") << endl;
  cout << s.isNumber("e9") << endl;
  cout << s.isNumber("0e") << endl;
  cout << s.isNumber(".") << endl;
  cout << s.isNumber(".1") << endl;
  cout << s.isNumber("3.") << endl;
  cout << s.isNumber("-.3") << endl;
  cout << s.isNumber("+.3") << endl;
  cout << s.isNumber("46.e3") << endl;
  cout << s.isNumber("46e6.3") << endl;
  return 0;
}
