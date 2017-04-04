#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:

    // O(n*k^2)
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
      vector<vector<int>> res;
      int len = words.size();
      if (len <= 1) return res;
      unordered_map<string, int> um;
      um.clear();
      for (int i = 0; i < len; ++i) {
        string temp = words[i];
        reverse(temp.begin(), temp.end());
        um[temp] = i;
      }
      for (int i = 0; i < len; ++i) {
        int len2 = words[i].length();
        for (int j = 0; j <= len2; ++j) {
          string s1 = words[i].substr(0, j);
          string s2 = words[i].substr(j);
          if (isPalindrome(s1) && (um.find(s2) != um.end()) && um[s2] != i) {
            res.push_back(vector<int> {um[s2], i});
          }
          if (!s2.empty() && isPalindrome(s2) && (um.find(s1) != um.end() && um[s1] != i)) {
            res.push_back(vector<int> {i, um[s1]});
          }
        }
      }
      return res;
    }
    // time : O(k*n^2)
    // space : O(n)
    // 超时了...
    vector<vector<int>> palindromePairs2(vector<string>& words) 
    {
      vector<vector<int>> res;
      int len = words.size();
      if (len <= 1) return res;
      for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
          if (j != i) {
            if (isPalindrome(words[i] + words[j])) {
              res.push_back(vector<int>{i, j});
            }
          }
        }
      }
      return res;
    }

    // time : O(k)
    // space : O(1)
    bool isPalindrome(const string &s)
    {
      int len = s.length();
      if (len <= 1) return true;
      int i;
      for (i = 0; i < (len / 2); ++i) {
        if (s[i] != s[len - 1 - i]) break;
      }
      return (i == (len / 2));
    }
};


int main(int argc, char *argv[])
{
  vector<string> v { "abcd", "dcba", "lls", "s", "sssll" };
  Solution s;
  auto res = s.palindromePairs(v);
  for (auto &ele : res) {
    for (auto &e : ele) {
      cout << e << "\t";
    }
    cout << endl;
  }
  return 0;
}
