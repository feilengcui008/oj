#include <string>
#include <iostream>
#include <stack>
#include <cstring>
#include <deque>

using namespace std;

class Solution {
 public:
  int calculate(string s) {
    deque<int> number;
    deque<char> op;
    int len = s.length();
    if (len == 0) return 0;
    for (int i = 0; i < len; ++i) {
      if (s[i] == ' ') continue;
      if (s[i] >= '0' && s[i] <= '9') {
        // get the number
        string temp = "";
        while (s[i] >= '0' && s[i] <= '9') {
          temp.push_back(s[i]);
          i++;
        }
        i--;  // notice this
        if (!op.empty() && op.back() == '*') {
          int n = number.back();
          number.pop_back();
          number.push_back(n * atoi(temp.c_str()));
          op.pop_back();
        } else if (!op.empty() && op.back() == '/') {
          int n = number.back();
          number.pop_back();
          number.push_back(n / atoi(temp.c_str()));
          op.pop_back();
        } else {
          number.push_back(atoi(temp.c_str()));
        }
      } else {
        // operator
        op.push_back(s[i]);
      }
    }
    while (!op.empty()) {
      char c = op.front();
      op.pop_front();
      int op1 = number.front();
      number.pop_front();
      int op2 = number.front();
      number.pop_front();
      if (c == '-') number.push_front(op1 - op2);
      if (c == '+') number.push_front(op1 + op2);
    }
    return number.front();
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string s1 = " 1 - 1 +1";
  string s2 = " 1 /3 + 2 *4*2";
  string s3 = "0-2147483647";
  cout << s.calculate(s1) << endl;
  cout << s.calculate(s2) << endl;
  cout << s.calculate(s3) << endl;
  return 0;
}
