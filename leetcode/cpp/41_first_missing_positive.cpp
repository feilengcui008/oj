#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
  // time: O(n), space: O(1)
  // 注意这个事实: 任意k个整数缺的第一个正整数一定在范围[1, k+1]内
  // 所以可以适用nums[i]代表i+1是否存在，思想和正整数查找唯一重复元素
  // 类似，都是利用所求元素的取值范围在给定数组的下标长度范围内。
  int firstMissingPositive(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 1;
    int i = 0;
    while (i < size) {
      if (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i]) {
        swap(nums[nums[i] - 1], nums[i]);
      } else {
        i++;
      }
    }
    for (int i = 0; i < size; ++i) {
      if (nums[i] != i + 1) return i + 1;
    }
    return nums[size - 1] + 1;
  }
};

int main(int argc, char* argv[]) {
  vector<int> v{1, 2, 0};
  vector<int> v1{3, 4, -1, 1};
  Solution s;
  cout << s.firstMissingPositive(v) << endl;
  cout << s.firstMissingPositive(v1) << endl;
  return 0;
}
