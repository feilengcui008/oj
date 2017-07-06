#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct comparator {
 public:
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
  }
};

class Solution {
 public:
  // time : O(nlogn) + 2O(n) + O(k)
  // space : 2O(n) + O(k)
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> um;
    vector<int> res;
    um.clear();
    // O(n)
    for (auto &ele : nums) {
      um[ele]++;
    }
    // O(n)
    vector<pair<int, int>> temp(um.begin(), um.end());
    // O(nlogn)
    sort(temp.begin(), temp.end(), comparator());
    // O(k)
    for (int i = 0; i < k; ++i) {
      res.push_back(temp[i].first);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v{2, 2, 2, 1, 1, 3, 4, 4, 4, 4};
  Solution s;
  auto res = s.topKFrequent(v, 3);
  for (auto &ele : res) {
    cout << ele << endl;
  }
  return 0;
}
