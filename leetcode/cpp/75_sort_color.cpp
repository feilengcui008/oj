#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
  // time: O(n), space: O(1)
  // 循环不变性质: [0, f-1]为0, [f, i]为1, [e, size-1]为2
  void sortColors(vector<int> &nums) {
    int size = nums.size();
    if (size <= 1) return;
    int f = 0, e = size - 1, i = 0;
    while (i <= e) {
      if (nums[i] == 0) {
        swap(nums[f], nums[i]);
        f++;
        i++;
      } else if (nums[i] == 2) {
        swap(nums[e], nums[i]);
        e--;
      } else {
        i++;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v{0, 2, 1, 2, 1, 0};
  s.sortColors(v);
  for (auto &ele : v) {
    cout << ele << endl;
  }
  return 0;
}
