#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
 public:
  // time : O(n), space : O(n)
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    // corner case
    if (nums1.size() == 0 || nums2.size() == 0) return res;
    unordered_map<int, int> um;
    um.clear();
    for_each(nums1.begin(), nums1.end(), [&um](int x)->void { um[x] = 1; });
    for_each(nums2.begin(), nums2.end(), [&](int x)->void {
      if (um[x] == 1) {
        res.push_back(x);
        um[x] = 0;
      }
    });
    return res;
  }

  // time : O(n), space : O(n)
  vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int len1 = nums1.size();
    int len2 = nums2.size();
    unordered_map<int, int> um;
    um.clear();
    for (int i = 0; i < len1; ++i) {
      if (um.find(nums1[i]) == um.end()) {
        um[nums1[i]] = 1;
      }
    }
    for (int i = 0; i < len2; ++i) {
      if (um[nums2[i]] == 1) {
        res.push_back(nums2[i]);
        um[nums2[i]]++;
      }
    }
    return res;
  }
};
