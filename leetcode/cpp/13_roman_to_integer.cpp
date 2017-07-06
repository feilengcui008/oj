#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    int size = s.size();
    int i = 0, res = 0;
    // find 'M'
    if (s[i] == 'M') {
      while (i < size && s[i] == 'M') {
        res += 1000;
        i++;
      }
    }
    i = handleTerm(s, i, 'C', 'D', 'M', res);
    cout << i << endl;
    i = handleTerm(s, i, 'X', 'L', 'C', res);
    cout << i << endl;
    i = handleTerm(s, i, 'I', 'V', 'X', res);
    return res;
  }

  int handleTerm(string num, int i, char s, char m, char b, int &sum) {
    int size = num.size();
    if (i + 1 >= size) {
      if (i + 1 == size) {
        sum += um_[num[i]];
        return i + 1;
      }
      return i;
    }

    if (num[i] == b) {
      while (i < size && num[i] == b) {
        sum += um_[b];
        i++;
      }
    }

    if (num[i] == m) {
      while (i < size && num[i] == m) {
        sum += um_[m];
        i++;
      }
      while (i < size && num[i] == s) {
        sum += um_[s];
        i++;
      }
    }
    if (num[i] == s) {
      if (num[i + 1] == b) {
        sum += (um_[b] - um_[s]);
        i += 2;
      } else if (num[i + 1] == m) {
        sum += (um_[m] - um_[s]);
        i += 2;
      } else {
        while (i < size && num[i] == s) {
          sum += um_[s];
          i++;
        }
      }
    }
    return i;
  }

 private:
  unordered_map<char, int> um_{{'I', 1},
                               {'V', 5},
                               {'X', 10},
                               {'L', 50},
                               {'C', 100},
                               {'D', 500},
                               {'M', 1000}, };
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.romanToInt("X") << endl;
  cout << s.romanToInt("MM") << endl;
  cout << s.romanToInt("MCMLXXX") << endl;  // 1980
  cout << s.romanToInt("DCXXI") << endl;    // 621
  cout << s.romanToInt("CCX") << endl;      // 210
  return 0;
}
