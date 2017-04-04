#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

class Solution {
  public:
    bool wordPattern(string pattern, string str) 
    {
      vector<string> splits;
      split(str, string(" "), splits);
      int len1 = pattern.length();
      int len2 = splits.size();
      if (len1 != len2) return false;
      unordered_map<char, vector<int>> um1;
      vector<vector<int>> v1;
      unordered_map<string, vector<int>> um2;
      vector<vector<int>> v2;
      um1.clear(); um2.clear();
      // O(n1)
      for (int i = 0; i < len1; ++i) {
        if (um1.find(pattern[i]) == um1.end()) {
          um1[pattern[i]] = vector<int>();
          um1[pattern[i]].push_back(i);
        }
      }
      // O(n1)
      for (int i = 0; i < len2; ++i) {
        if (um2.find(splits[i]) == um2.end()) {
          um2[splits[i]] = vector<int>();
          um2[splits[i]].push_back(i);
        }
      }
      for (auto &&ele : um1) {
        v1.push_back(ele.second);
      }
      for (auto &&ele : um2) {
        v2.push_back(ele.second);
      }
      // O(n * logn)
      sort(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());
      return v1 == v2;
    }

    void split(const string& src, const string& separator, vector<string>& dest)
    {
      string substring;
      string::size_type start = 0, index;
      do {
        index = src.find_first_of(separator, start);
        if (index != string::npos) {    
          substring = src.substr(start, index-start);
          dest.push_back(substring);
          start = src.find_first_not_of(separator, index);
          if (start == string::npos) return;
        }
      } while(index != string::npos);
      substring = src.substr(start);
      dest.push_back(substring);
    }

};


int main(int argc, char *argv[])
{
  Solution s;
  cout << s.wordPattern(string("abba"), string("dog cat cat dog")) << endl;
  cout << s.wordPattern(string("abba"), string("dog cat cat fish")) << endl;
  return 0;
}
