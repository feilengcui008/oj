#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  // todo : how to use the condition : numbers are between 1~n
  int findDuplicate(vector<int>& nums) { return anotherMethod(nums); }
  // another method : sort first, but the array is modified
  // time : O(nlog(n)) + O(n), space : O(1)
  int anotherMethod(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) return -1;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < len; ++i) {
      if (nums[i] == nums[i - 1]) return nums[i];
    }
    return -1;
  }
};