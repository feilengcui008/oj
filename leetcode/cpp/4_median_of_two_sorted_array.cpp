#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    if ((len1 + len2) % 2 != 0) {
      return findKthSortedArrays(nums1, len1, nums2, len2,
                                 (len1 + len2 + 1) / 2);
    } else {
      return (findKthSortedArrays(nums1, len1, nums2, len2, (len1 + len2) / 2) +
              findKthSortedArrays(nums1, len1, nums2, len2,
                                  (len1 + len2) / 2 + 1)) /
             2.0;
    }
  }

 private:
  double findKthSortedArrays(vector<int> &num1, int leftlen1, vector<int> &num2,
                             int leftlen2, int k) {
    // exchange for convenience
    if (leftlen1 > leftlen2) {
      return findKthSortedArrays(num2, leftlen2, num1, leftlen1, k);
    }
    // stop condition for nums1 length
    if (leftlen1 == 0) {
      return num2[num2.size() - leftlen2 + k - 1];
    }
    // stop condition for k
    if (k == 1) {
      return num1[num1.size() - leftlen1] < num2[num2.size() - leftlen2]
                 ? num1[num1.size() - leftlen1]
                 : num2[num2.size() - leftlen2];
    }
    int skip = min(k / 2, leftlen1);
    int leftindex = num1.size() - leftlen1 + skip - 1;
    int rightindex = num2.size() - leftlen2 + (k - skip) - 1;
    if (num1[leftindex] < num2[rightindex]) {
      return findKthSortedArrays(num1, leftlen1 - skip, num2, leftlen2,
                                 k - skip);
    } else {
      return findKthSortedArrays(num1, leftlen1, num2, leftlen2 - (k - skip),
                                 skip);
    }
  }
};

int main(int argc, char **argv) {
  Solution s;
  vector<int> v1{1, 3, 5, 8, 10};
  vector<int> v2{2, 4, 7, 9};
  cout << s.findMedianSortedArrays(v1, v2) << endl;
  v1 = {};
  v2 = {1};
  cout << s.findMedianSortedArrays(v1, v2) << endl;
  vector<int> v11 = {1, 2};
  vector<int> v22 = {1, 2};
  cout << s.findMedianSortedArrays(v11, v22) << endl;
  v11 = {4};
  v22 = {1, 2, 3, 5, 6};
  cout << s.findMedianSortedArrays(v11, v22) << endl;
  v11 = {5};
  v22 = {1, 2, 3, 4, 6};
  cout << s.findMedianSortedArrays(v11, v22) << endl;
  v11 = {1};
  v22 = {2, 3, 4, 5, 6};
  cout << s.findMedianSortedArrays(v11, v22) << endl;
}
