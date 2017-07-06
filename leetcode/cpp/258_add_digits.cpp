class Solution {
 public:
  int addDigits(int num) {
    int res = 0;
    while (num) {
      res += (num % 10);
      num /= 10;
    }
    if (res <= 9) return res;
    return addDigits(res);
  }
};
