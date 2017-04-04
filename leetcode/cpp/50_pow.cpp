#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
  public:
    // time: O(logn), space: O(1)
    double myPow(double x, int n)
    {
      if (n == 0) return 1;
      if (x == 1) return 1;
      if (n < 0) {
        // handle overflow...
        if (n == numeric_limits<int>::min()) {
          return (1.0 / (myPow(x, -n-1) * x));
        }
        return (1.0 / myPow(x, -n));
      }
      if (n % 2 == 0) {
        double r = myPow(x, n / 2);
        return r * r;
      } else {
        double r = myPow(x, n / 2);
        return r * r * x;
      }
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.myPow(2.0, 4) << endl;
  cout << s.myPow(1.0, numeric_limits<int>::min()) << endl;
  return 0;
}
