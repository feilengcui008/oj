#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int len = nums.size();
    int sum = (1 + len) * len / 2;
    int res = 0;
    for (auto& ele : nums) {
      res += ele;
    }
    return sum - res;
  }
};
