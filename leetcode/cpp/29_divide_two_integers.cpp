#include <limits.h>
#include <stdint.h>

class Solution {

  public:
    int divide(int dividend, int divisor)
    {
      if (divisor == 0) return INT_MAX;
      bool flag = true;
      if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
        flag = false;
      }
      int64_t n = dividend, m = divisor;
      n = n < 0 ? -n : n;
      m = m < 0 ? -m : m;
      int64_t c = 0, t, temp;
      while (n >= m) {
        t = 1, temp = m;
        while ((temp<<1) <= n) {
          temp <<= 1;
          t <<= 1;
        }
        c += t;
        if (flag && c > INT_MAX) return INT_MAX;
        if (!flag && c - INT_MAX > 1) return INT_MAX;
        n -= temp;
      }
      return flag ? c : -c;
    }
};
