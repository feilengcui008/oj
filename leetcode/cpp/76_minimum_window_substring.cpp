#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(n), space: O(len(t))
  // 用循环不变式证明?
  string minWindow(string s, string t) {
    vector<int> um(128, 0);
    int counter = 0;
    for (auto c : t) {
      um[c]++;
      counter++;
    }
    int begin = 0, end = 0, head, l = s.size();
    int d = numeric_limits<int>::max();
    while (end < l) {
      if (um[s[end]] > 0) {
        counter--;
      }
      um[s[end]]--;
      end++;
      while (counter == 0) {
        // update substring position and length
        if (end - begin < d) {
          d = end - begin;
          head = begin;
        }
        if (um[s[begin]] == 0) {
          counter++;
        }
        um[s[begin]]++;
        begin++;
      }
    }
    return (d == numeric_limits<int>::max()) ? "" : s.substr(head, d);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
  cout << s.minWindow("aa", "aa") << endl;
  cout << s.minWindow("aabcdeeebcad", "bcd") << endl;
  cout << s.minWindow("bba", "ab") << endl;
  cout << s.minWindow("aab", "aab") << endl;
  cout << s.minWindow("babcaacabcabbbca", "aaabb") << endl;
  cout << s.minWindow("abcabdebac", "cda") << endl;
  cout << s.minWindow("aaabdabcefaecbef", "abc") << endl;
  cout << s.minWindow("baAaABabBba", "AbbB") << endl;
  return 0;
}
