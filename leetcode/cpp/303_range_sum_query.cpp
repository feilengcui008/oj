#include <vector>

using namespace std;

// 这题考什么?加缓存?
class NumArray {
 public:
  NumArray(vector<int> &nums) { nums_ = nums; }

  int sumRange(int i, int j) {
    int res = 0;
    if (i < 0) i = 0;
    if (j >= static_cast<int>(nums_.size())) j = nums_.size() - 1;
    while (i <= j) {
      res += nums_[i];
      i++;
    }
    return res;
  }

 private:
  vector<int> nums_;
};

// Your NumArray object will be instantiated and called as such:

// NumArray numArray(nums);

// numArray.sumRange(0, 1);

// numArray.sumRange(1, 2);
