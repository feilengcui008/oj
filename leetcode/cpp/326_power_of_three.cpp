class Solution {
 public:
  bool isPowerOfThree(int n) {
    // 3486784401 = pow(3, 20)
    return (n > 0 && 3486784401 % n == 0) ? true : false;
  }
};
