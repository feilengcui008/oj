#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    return nums[size / 2];
  }

  // 遇到一对不相同的就消去
  int anotherMethod(vector<int>& nums) {
    // assert(nums.size() > 0)
    int i, len = nums.size();
    int res;
    int count = 0;
    for (i = 0; i < len; ++i) {
      if (count == 0) res = nums[i];
      if (nums[i] == res)
        count++;
      else
        count--;
    }
    return res;
  }
};
