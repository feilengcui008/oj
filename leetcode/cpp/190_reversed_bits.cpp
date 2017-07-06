#include <cstdint>
#include <iostream>

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    uint32_t temp = n;
    for (int i = 0; i < 32; i++) {
      res += (temp & 1) << (31 - i);
      temp = temp >> 1;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  uint32_t temp = 8;
  std::cout << s.reverseBits(temp) << std::endl;
  return 0;
}
