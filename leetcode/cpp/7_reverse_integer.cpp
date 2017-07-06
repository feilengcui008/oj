#include <cmath>
#include <iostream>

class Solution {
 public:
  int reverse(int x) {
    bool flag = x > 0 ? true : false;
    if (!flag) x = -x;
    int n = 0, i, res = 0;
    int m = x;
    while (m) {
      n++;
      m = m / 10;
    }
    m = x;
    for (i = 0; i < n; i++) {
      res += (m % 10) * pow(10, n - i - 1);
      if (res < 0) {  // overflow
        return 0;
      }
      m = m / 10;
    }
    if (flag)
      return res;
    else
      return -res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.reverse(-123) << "\n";
  std::cout << s.reverse(3) << "\n";
  std::cout << s.reverse(0) << "\n";
  return 0;
}
