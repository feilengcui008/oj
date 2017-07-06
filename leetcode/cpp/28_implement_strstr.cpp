#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    return basicMethod(haystack, needle);
  }

  int basicMethod(string haystack, string needle) {
    int len1 = haystack.length();
    int len2 = needle.length();
    if (len2 == 0) return 0;
    if (len1 == 0 || len1 < len2) return -1;
    int i, j;
    for (i = 0; i <= len1 - len2; ++i) {
      for (j = 0; j < len2; ++j) {
        if (haystack[i + j] != needle[j]) break;
      }
      if (j == len2) return i;
    }
    return -1;
  }

  int kmp(string haystack, string needle) {
    int len1 = haystack.length();
    int len2 = needle.length();
    vector<int> nextArray;
    if (len1 == 0 || len2 == 0 || len1 < len2) return -1;
    // compute next array
    // begin kmp
    return -1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string haystack = "present";
  string needle = "se";
  string needle1 = "";
  string needle2 = "nt";
  cout << s.basicMethod(haystack, needle) << endl;
  cout << s.basicMethod(haystack, needle1) << endl;
  cout << s.basicMethod(haystack, needle2) << endl;
  return 0;
}
