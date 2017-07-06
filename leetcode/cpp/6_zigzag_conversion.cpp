#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  // time: O(n), space: O(n)
  string convert(string s, int numRows) {
    int size = s.size();
    if (size <= numRows) return s;
    vector<string> res = vector<string>(numRows);
    bool down = true;
    for (int i = 0; i < size;) {
      if (down) {
        for (int j = 0; j < numRows; ++j) {
          if (i < size) {
            res[j].push_back(s[i]);
            i++;
          }
        }
        down = false;
      } else {
        for (int j = 0; j < numRows - 2; ++j) {
          if (i < size) {
            res[numRows - j - 2].push_back(s[i]);
            i++;
          }
        }
        down = true;
      }
    }
    string r = "";
    for (int i = 0; i < numRows; ++i) {
      r += res[i];
    }
    return r;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string s1 = "PAYPALISHIRING";
  int num = 3;
  string s2 = "ABCD";
  string s3 = "ABCDE";
  cout << s.convert(s1, num) << endl;
  ;
  cout << s.convert(s2, num) << endl;
  cout << s.convert(s3, 3) << endl;
  return 0;
}
