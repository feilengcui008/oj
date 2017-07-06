#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(logn), space: O(1)
  // notice: overflow and divide by 0
  int mySqrt(int x) {
    // binary search
    int l = 0, r = x;
    int t;
    while (l <= r) {
      t = l + (r - l) / 2;
      if (t == 0) {
        // 0, 0 or 0, 1
        return x;
      }
      if (t == x / t)
        return t;
      else if (t < x / t) {
        l = t + 1;
      } else {
        r = t - 1;
      }
    }
    return r;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.mySqrt(16) << endl;
  cout << s.mySqrt(15) << endl;
  cout << s.mySqrt(2147395599) << endl;
  cout << s.mySqrt(0) << endl;
  return 0;
}
