#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  // time: O(n^2), space: O(n)
  // actually we can use next permutation routine
  // next permutation way is much more clear
  string getPermutation(int n, int k) {
    vector<bool> state(n, false);
    string res;
    getNextChar(state, n, k, res);
    return res;
  }

  void getNextChar(vector<bool> &state, int n, int k, string &res) {
    // avoid compute 0!
    if (state.size() == 1) {
      res.push_back(1 + '0');
      return;
    }
    if ((int)res.size() == (int)state.size()) return;
    if (k == 0) {
      for (int i = 0; i < (int)state.size(); ++i) {
        if (state[i] == false) {
          res.push_back(i + 1 + '0');
        }
      }
      return;
    }

    int t = order(n - 1), kth = k / t;
    // this can be tricky...
    if (k % t != 0) kth += 1;
    int saved = kth;
    int i;
    // find which char we should choose
    for (i = 0; i < (int)state.size(); ++i) {
      if (state[i] == false) kth--;
      if (kth == 0) break;
    }
    res.push_back(i + 1 + '0');
    state[i] = true;
    // go to find next char
    return getNextChar(state, n - 1, k - t * (saved - 1), res);
  }

  inline int order(int k) {
    int res = 1;
    while (k > 0) {
      res *= k;
      k--;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.getPermutation(3, 3) << endl;
  cout << s.getPermutation(1, 1) << endl;
  cout << s.getPermutation(2, 1) << endl;
  cout << s.getPermutation(3, 2) << endl;
  return 0;
}
