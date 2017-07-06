#include <cmath>
#include <iostream>

class Solution {
 public:
  // another way : may use the reverse integer code
  // o(n)
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int n = 0;
    int i, j;
    int temp = x;
    while (temp) {
      n++;
      temp = temp / 10;
    }
    // std::cout << n << std::endl;
    i = 0;
    j = n - 1;
    while (i < j) {
      if ((x / (int)pow(10, i)) % 10 != (x / (int)pow(10, j)) % 10) {
        break;
      } else {
        i++;
        j--;
      }
    }
    if (i < j)
      return false;
    else
      return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.isPalindrome(12321) << std::endl;
  std::cout << s.isPalindrome(1221) << std::endl;
  std::cout << s.isPalindrome(22) << std::endl;
  return 0;
}
