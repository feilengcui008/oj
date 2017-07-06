#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    int len = s.size();
    if (len == 0) return res;
    restore(res, s, string(""), 0, 0);
    return res;
  }

  void restore(vector<string> &v, string &s, string res, int currentindex,
               int currentpart) {
    // we only care about the right conditions
    int len = s.size();
    if (currentpart >= 4 || currentindex >= len) {
      // cout << "res: " << res << endl;
      if (currentindex >= len && currentpart == 4) {
        v.push_back(string(res.begin(), res.end() - 1));
      }
      return;
    }
    if (currentindex <= len - 1) {
      restore(v, s, res + s[currentindex] + ".", currentindex + 1,
              currentpart + 1);
    }
    string temp("");
    temp.push_back(s[currentindex]);
    if (currentindex + 1 <= len - 1) {
      // handle the case start by 0
      if (s[currentindex] != '0') {
        temp.push_back(s[currentindex + 1]);
        restore(v, s, res + temp + ".", currentindex + 2, currentpart + 1);

        if (currentindex + 2 <= len - 1) {
          temp.push_back(s[currentindex + 2]);
          if (temp <= "255") {
            restore(v, s, res + temp + ".", currentindex + 3, currentpart + 1);
          }
        }
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string s1 = "25525511135";
  string s2 = "0000";
  string s3 = "010010";
  auto res = s.restoreIpAddresses(s1);
  for (auto &ele : res) {
    cout << ele << endl;
  }
  cout << "=======" << endl;
  res = s.restoreIpAddresses(s2);
  for (auto &ele : res) {
    cout << ele << endl;
  }
  cout << "=======" << endl;
  res = s.restoreIpAddresses(s3);
  for (auto &ele : res) {
    cout << ele << endl;
  }
  return 0;
}
