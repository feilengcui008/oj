#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  // time: O(n*m), space: O(maxWidth)
  // 细节题目...
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    if (maxWidth == 0) return vector<string>{""};
    int size = words.size();
    vector<string> res;
    vector<string> temp;
    int l = 0, i = 0;
    while (i < size) {
      if (l + (int)words[i].length() > maxWidth) {
        // process temp
        int space = maxWidth - l + 1, n = temp.size();
        if (n <= 1) {
          for (int j = temp[0].length(); j < maxWidth; ++j) {
            temp[0].push_back(' ');
          }
          res.push_back(temp[0]);
          l = 0;
          temp.clear();
          continue;
        }
        int avg = space / (n - 1), left = space - avg * (n - 1);
        string t = "";
        for (int j = 0; j < n; ++j) {
          t += temp[j];
          t.push_back(' ');
          for (int k = 0; k < avg; ++k) t.push_back(' ');
          if (j < left) t.push_back(' ');
        }
        t = t.substr(0, t.length() - 1 - avg);
        res.push_back(t);
        // reset
        l = 0;
        temp.clear();
      } else {
        l += (words[i].length() + 1);
        temp.push_back(words[i]);
        i++;
      }
    }
    string s = "";
    for (int j = 0; j < (int)temp.size(); ++j) {
      s += temp[j];
      s.push_back(' ');
    }
    for (int j = s.length(); j < maxWidth; ++j) {
      s.push_back(' ');
    }
    res.push_back(s.substr(0, maxWidth));
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<string> v = {"This", "is",   "an",            "example",
                      "of",   "text", "justification."};
  vector<string> v1 = {""};
  vector<string> v2 = {"a", "b", "c", "d", "e"};
  vector<string> v3 = {""};
  Solution s;
  auto res = s.fullJustify(v, 16);
  for (auto &ele : res) {
    cout << ele << " - " << ele.length() << endl;
  }
  cout << "====" << endl;
  auto res1 = s.fullJustify(v1, 2);
  for (auto &ele : res1) {
    cout << ele << " - " << ele.length() << endl;
  }
  cout << "====" << endl;
  auto res2 = s.fullJustify(v2, 3);
  for (auto &ele : res2) {
    cout << ele << " - " << ele.length() << endl;
  }
  cout << "====" << endl;
  auto res3 = s.fullJustify(v3, 2);
  for (auto &ele : res3) {
    cout << ele << " - " << ele.length() << endl;
  }
  return 0;
}
