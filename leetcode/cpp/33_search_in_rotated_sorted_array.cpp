#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  int search(vector<int> &nums, int target) {
    return findInRotatedArray(nums, 0, nums.size() - 1, target);
  }

  // rotated sorted array二分查找
  int findInRotatedArray(const vector<int> &v, int left, int right,
                         int target) {
    if (left < 0 || right > static_cast<int>(v.size()) || left > right)
      return -1;
    int middle = -1;
    while (left < right) {
      middle = left + (right - left) / 2;
      if (v[middle] == target) {
        return middle;
      }
      if (v[left] <= v[middle]) {
        if (v[left] <= target && target < v[middle]) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      } else {
        if (v[middle] < target && target <= v[right]) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }
    }
    return v[left] == target ? left : -1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v{3, 1};
  vector<int> v1{1};
  cout << s.search(v, 1) << endl;
  cout << s.search(v1, 1) << endl;
  return 0;
}
