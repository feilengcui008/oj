#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // time: O(n^2), space: O(n)
    vector<string> letterCombinations(string digits)
    {
      vector<string> res;
      int size = digits.length();
      if (size == 0) return res;
      for (int i = 0; i < size; ++i) {
        if (res.size() == 0) {
          for (const auto &ele : arr_[digits[i] - '0']) {
            string t;
            t.push_back(ele);
            res.push_back(t);
          }
        } else {
          int l = res.size();
          for (int m = 0; m < l; ++m) {
            string temp = res[m];
            int s = arr_[digits[i] - '0'].length();
            if (s == 0) break;  // go out of this loop
            res[m].push_back(arr_[digits[i] - '0'][0]);
            // O(1)
            for (int k = 0; k < s - 1; ++k) {
              string t = temp;
              t.push_back(arr_[digits[i] - '0'][k + 1]);
              res.push_back(t);
            }
          }
        }
      } 
      return res;
    }
  private:
    vector<string> arr_{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

int main(int argc, char *argv[])
{
  string digits{"23"};
  Solution s;
  auto res = s.letterCombinations(digits);
  for (auto &ele : res) {
    cout << ele << endl;
  }
  return 0;
}
