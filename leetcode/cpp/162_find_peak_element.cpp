#include <vector>

using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) return 0;
    if (nums[0] > nums[1]) return 0;
    int i = 1;
    for (i = 1; i < len - 1; ++i) {
      if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
    }
    if (nums[i] > nums[i - 1]) return i;
    return -1;
  }
};
