#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
 public:
  // time: O(n * l * m), space: O(l * m)
  // how to skip the i pointer more efficiently?
  vector<int> findSubstring(string s, vector<string> &words) {
    int size = s.size();
    int l = words.size();
    unordered_map<string, int> um;
    vector<int> res;
    if (size == 0 || l == 0) return res;
    int c = 0, wl = words[0].length();
    for (auto &ele : words) {
      if (um.find(ele) == um.end()) {
        um[ele] = 0;
      } else {
        um[ele] += 1;
      }
    }
    auto saved = um;
    for (int i = 0; i <= size - wl * l; ++i) {
      int k = i, t = 0;
      auto um1 = um;
      for (int j = 0; j < l; ++j) {
        string temp(s.begin() + k, s.begin() + k + wl);
        if (um1.find(temp) == um1.end()) break;
        if (um1[temp] - um[temp] > saved[temp]) break;  // already appeared
        um1[temp] += 1;
        t++;
        k += wl;
      }
      if (t == l) {
        res.push_back(i);
        c += 1;
        um = um1;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  string str = "barfoothefoobarman";
  string str1 = "wordgoodgoodgoodbestword";
  vector<string> v{"foo", "bar"};
  vector<string> v1{"word", "good", "best", "good"};
  Solution s;
  auto res = s.findSubstring(str, v);
  for (auto &ele : res) {
    cout << ele << endl;
  }
  cout << endl;
  res = s.findSubstring(str1, v1);
  for (auto &ele : res) {
    cout << ele << endl;
  }
  return 0;
}
