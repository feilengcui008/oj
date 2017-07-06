#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(n), space: O(1)
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // from back to front
    int i = m - 1, j = n - 1, idx = m + n - 1;
    while (idx >= 0) {
      if (j < 0) {
        break;
      }
      if (i < 0) {
        nums1[idx] = nums2[j];
        j--;
        idx--;
        continue;
      }
      if (nums1[i] > nums2[j]) {
        nums1[idx] = nums1[i];
        i--;
      } else {
        nums1[idx] = nums2[j];
        j--;
      }
      idx--;
    }
  }
};

int main(int argc, char* argv[]) {
  vector<int> v1{1, 3, 4, 0, 0};
  vector<int> v2{2, 5};
  Solution s;
  s.merge(v1, 3, v2, 2);
  for (auto ele : v1) {
    cout << ele << endl;
  }
  cout << endl;
  v1 = {1};
  v2 = {};
  s.merge(v1, 1, v2, 0);
  for (auto ele : v1) {
    cout << ele << endl;
  }
  cout << endl;
  v1 = {4, 5, 6, 0, 0, 0};
  v2 = {1, 2, 3};
  s.merge(v1, 3, v2, 3);
  for (auto ele : v1) {
    cout << ele << endl;
  }
  return 0;
}
