#include <vector>

using namespace std;

class Solution {
 public:
  // todo : add the O(n) linear time method
  vector<int> countBits(int num) { return directMethod(num); }

  // time : O(n * sizeof(int)), space : O(n)
  vector<int> directMethod(int num) {
    vector<int> res;
    for (int i = 0; i <= num; ++i) {
      res.push_back(countOne(i));
    }
    return res;
  }

  int countOne(int n) {
    int res = 0;
    while (n != 0) {
      if ((n & 1) != 0) res++;
      n >>= 1;
    }
    return res;
  }
};
