#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    // time: O(n) space: O(1)
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
      int max = 0, count = 0, size = nums.size();
      for (int i = 0; i < size; ++i) {
        if (nums[i] == 0) {
          max = count > max ? count : max;
          count = 0;
        } else {
          count++;
        }
      }
      return count > max ? count : max;
    }
};


int main(int argc, char *argv[])
{
  vector<int> nums {1, 1, 0, 1, 1, 1};
  Solution s;
  cout << s.findMaxConsecutiveOnes(nums) << endl;
  return 0;
}

