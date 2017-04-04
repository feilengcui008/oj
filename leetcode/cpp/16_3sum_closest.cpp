#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
  public:
    // time: O(n^2), space: O(1)
    // 排序序列双指针夹逼法查找的正确性证明
    // 假设双指针为preIndex, nextIndex
    //
    // 如果nums[preIndex] + nums[nextIndex] < target，则preIndex++
    // [因为此时对于固定的preIndex，对于k in [preIndex+1, nextIndex]
    // 始终有nums[preIndex] + nums[k] <= nums[preIndex] + nums[nextIndex] < target，
    // 这样直接去掉了n-1对preIndex和nextIndex组合，对于本题的与目标值差的绝对值
    // (即点距)最小同样适用]，此即为循环不变式，所以每次迭代丢掉n-1个组合是正确的。
    int threeSumClosest(vector<int>& nums, int target)
    {
      int size = nums.size();
      if (size < 3) return 0;
      sort(nums.begin(), nums.end()); 
      int closest = nums[0] + nums[1] + nums[2];
      for (int i = 0; i < size; ++i) {
        int t = target - nums[i];
        int j = i + 1, k = size - 1;
        while (j < k) {
          int s = nums[j] + nums[k];
          if (abs(s - t) < abs(closest - target)) closest = s + nums[i];
          if (s == t) return closest;
          else if (s > t) {
            k--;
          } else {
            j++;
          }
        }
        while (i < size && nums[i] == nums[i+1]) i++;
      }
      return closest;
    }
};


int main(int argc, char **argv) 
{
  vector<int> nums = {-1, 2, 1, -4};
  Solution s;
  cout << s.threeSumClosest(nums, 1) << endl;
  return 0;
}
