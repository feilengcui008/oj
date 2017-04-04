#include <iostream>

class Solution {
  public:
    int integerBreak(int n) 
    {
      // 大于4后的整数总可以拆分成1, 2, 3的序列和使得
      // 其乘积比原来大

      // corner case n >= 2
      if (n == 2) return 1;
      if (n == 3) return 2;
      if (n == 4) return 4;
      int product = 1;
      for (;;) {
        if (n <= 4) break;
        product *= 3;
        n -= 3;
      }
      return (product * n);
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  std::cout << s.integerBreak(2) << std::endl;
  std::cout << s.integerBreak(10) << std::endl;
  return 0;
}
