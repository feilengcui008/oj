#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  // at least most times of each common elements
  // time : O(n1 + n2), space : O(n1)
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    if (nums1.size() == 0 || nums2.size() == 0) return res;
    unordered_map<int, int> um;
    um.clear();
    // O(n1)
    for (auto &&ele : nums1) {
      um[ele]++;
    }
    // O(n2)
    for (auto &&ele : nums2) {
      if (um[ele] > 0) {
        res.push_back(ele);
        um[ele]--;
      }
    }
    return res;
  }
  // the most times of each common elements
  vector<int> intersect1(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    if (nums1.size() == 0 || nums2.size() == 0) return res;
    unordered_map<int, int> um;
    vector<int> common;
    um.clear();
    // O(n1)
    for (auto &&ele : nums1) {
      um[ele]++;
    }
    // O(n2)
    for (auto &&ele : nums2) {
      if (um[ele] > 0) {
        res.push_back(ele);
        common.push_back(ele);
        um[ele]--;
      }
    }
    // O((n1 - n2) * m), m为nums1/nums2差异最大长度
    for (auto &&ele : common) {
      if (um[ele] > 0) {
        for (int i = 0; i < um[ele]; ++i) {
          res.push_back(ele);
        }
      }
    }
    return res;
  }
};
