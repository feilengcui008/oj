#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<unsigned char, int> um;
    int size = s.length();
    int longest = 0;
    int start = 0;
    for (int end = 0; end < size; end++) {
      if (um.find(s[end]) != um.end()) {
        // notice
        int temp = um.find(s[end])->second + 1;
        start = temp > start ? temp : start;
      }
      um[s[end]] = end;
      longest = ((end + 1 - start) > longest) ? (end + 1 - start) : longest;
    }
    return longest;
  }
};

int main(int argc, char *argv[]) {

  Solution s;
  cout << s.lengthOfLongestSubstring("dvdf") << endl;
  cout << s.lengthOfLongestSubstring("aa") << endl;
  cout << s.lengthOfLongestSubstring("aacdefalkm") << endl;
  cout << s.lengthOfLongestSubstring("asjrgapa") << endl;
  return 0;
}
