#include <cstdint>
#include <iostream>

class Solution {
 public:
  // way one
  uint32_t hammingWeight(uint32_t n) {
    uint32_t temp = n;
    uint32_t res = 0;
    while (temp >> 1) {
      res += (temp & 1);
      temp = temp >> 1;
    }
    // last bit
    res += (temp & 1);
    return res;
  }

  // way two
  uint32_t hammingWeight2(uint32_t n) {
    uint32_t temp = n;
    uint32_t res = 0;
    while ((temp & (temp - 1)) != 0) {
      temp = temp & (temp - 1);
      res++;
    }
    // plus last bit
    return res + 1;
  }

  static void test() {
    Solution s;
    std::cout << "use >> method:" << s.hammingWeight(7) << std::endl;
    std::cout << "use v&(v-1) method:" << s.hammingWeight2(7) << std::endl;
  }
};
