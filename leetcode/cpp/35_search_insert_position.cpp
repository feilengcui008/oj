#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
  // time: O(logn), space: O(1)
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, lastSmallIndex = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] == target) {
        return m;
      } else if (nums[m] < target) {
        if (m > lastSmallIndex) lastSmallIndex = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return lastSmallIndex + 1;
  }
};

int main(int argc, char* argv[]) {
  vector<int> v{1, 3, 5, 6};
  Solution s;
  cout << s.searchInsert(v, 5) << endl;
  cout << s.searchInsert(v, 2) << endl;
  cout << s.searchInsert(v, 0) << endl;
  return 0;
}
