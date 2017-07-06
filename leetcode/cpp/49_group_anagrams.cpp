#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    int len = strs.size();
    // corner case
    if (len == 0) return res;
    unordered_map<string, vector<string>> um;
    um.clear();
    for (int i = 0; i < len; ++i) {
      string temp = strs[i];
      sort(temp.begin(), temp.end());
      if (um.find(temp) != um.end()) {
        um[temp].push_back(strs[i]);
      } else {
        um[temp] = vector<string>{strs[i]};
      }
    }
    for (auto &ele : um) {
      sort(ele.second.begin(), ele.second.end());
      res.push_back(std::move(ele.second));
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<string> v{"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution s;
  vector<vector<string>> res = s.groupAnagrams(v);
  for (auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << "\n";
  }
  return 0;
}
