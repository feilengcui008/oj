#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    // time: O(n^2), space: O(n)
    string frequencySort(string s)
    {
      int size = s.size();
      if (size <= 1) return s;
      unordered_map<unsigned char, int> um;
      vector<vector<unsigned char>> chars(size); 
      for (int i = 0; i < size; ++i) {
        um[s[i]] += 1;
      }
      for (const auto &ele: um) {
        chars[ele.second - 1].push_back(ele.first);  
      }
      string res;
      // O(n^2)
      for (int i = size - 1; i >= 0; --i) {
        if (chars[i].size() > 0) {
          for (const auto &ele: chars[i]) {
            for (int j = 0; j < i + 1; ++j) {
              res.push_back(ele);
            }  
          }
        }
      }
      return res;
    }
};


int main(int argc, char *argv[])
{
  string str{"tree"};
  Solution s;
  cout << s.frequencySort(str) << endl;
  cout << s.frequencySort("Aabb") << endl;
  return 0;
}
