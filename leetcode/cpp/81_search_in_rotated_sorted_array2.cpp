#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool search(vector<int> &nums, int target) {
    int res = findInRotatedArrayWithDuplicate(nums, 0, nums.size() - 1, target);
    return res == -1 ? false : true;
  }

  // rotated sorted array二分查找
  int findInRotatedArrayWithDuplicate(const vector<int> &v, int left, int right,
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
        if (v[left] == v[middle] && left != middle) {  // skip duplicate
          left++;
        } else {
          if (v[left] <= target && target < v[middle]) {
            right = middle - 1;
          } else {
            left = middle + 1;
          }
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
  vector<int> v2{2, 2, 2, 1};
  vector<int> v3{1, 3, 1, 1, 1};
  cout << s.search(v, 1) << endl;
  cout << s.search(v1, 1) << endl;
  cout << s.search(v2, 1) << endl;
  cout << s.search(v3, 3) << endl;
  return 0;
}
