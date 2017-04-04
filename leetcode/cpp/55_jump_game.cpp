#include <vector>

using namespace std;

class Solution {
  public:
    bool canJump(vector<int>& nums)
    {
      int size = nums.size();
      int currentEnd = 0, nextEnd = 0;
      for (int i = 0; i < size - 1; ++i) {
        nextEnd = nums[i] + i > nextEnd ? nums[i] + i : nextEnd;
        if (i == currentEnd) {
          if (currentEnd == nextEnd) break;
          currentEnd = nextEnd;
        }
      }
      return nextEnd >= size - 1;
    }
};
