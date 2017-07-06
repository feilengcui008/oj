#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int> &nums) {
    int len = nums.size();
    if (len <= 1) return;
    int index = 0;
    int i;
    for (i = 0; i < len; ++i) {
      // move non-zero number to front part
      if (nums[i] != 0) {
        nums[index] = nums[i];
        index++;
      }
    }
    // set the last part to 0
    while (index < len) {
      nums[index] = 0;
      index++;
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v{0, 1, 0, 3, 12};
  s.moveZeroes(v);
  for (auto &ele : v) {
    cout << ele << "\t";
  }
  return 0;
}
