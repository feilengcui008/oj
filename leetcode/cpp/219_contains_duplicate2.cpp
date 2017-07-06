#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  // time : O(n), space : O(n)
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> um;
    um.clear();
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
      if (um.find(nums[i]) != um.end()) {
        if (i - um[nums[i]] <= k) return true;
      }
      um[nums[i]] = i;
    }
    return false;
  }

  // time : O(n * k), space : O(1)
  bool containsNearbyDuplicate1(vector<int>& nums, int k) {
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j <= i + k && j < len; ++j) {
        if (nums[i] == nums[j]) return true;
      }
    }
    return false;
  }
};
