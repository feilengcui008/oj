#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  // time: O(n), space: O(N) N is number of a-z
  vector<string> findWords(vector<string> &words) {
    vector<string> res;
    unordered_set<unsigned char> set1{'q', 'w', 'e', 'r', 't',
                                      'y', 'u', 'i', 'o', 'p'};
    unordered_set<unsigned char> set2{'a', 's', 'd', 'f', 'g',
                                      'h', 'j', 'k', 'l'};
    unordered_set<unsigned char> set3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    // find from set1 first since it has higher properbility
    int size = words.size();
    for (int i = 0; i < size; ++i) {
      string temp = words[i];
      if (temp.size() == 0) continue;
      if (set1.find(toLower(temp[0])) != set1.end()) {
        int j = 1;
        for (; j < static_cast<int>(temp.size()); ++j) {
          if (set1.find(toLower(temp[j])) == set1.end()) break;
        }
        if (j == static_cast<int>(temp.size())) res.push_back(temp);
      } else if (set2.find(toLower(temp[0])) != set2.end()) {
        int j = 1;
        for (; j < static_cast<int>(temp.size()); ++j) {
          if (set2.find(toLower(temp[j])) == set2.end()) break;
        }
        if (j == static_cast<int>(temp.size())) res.push_back(temp);
      } else {
        int j = 1;
        for (; j < static_cast<int>(temp.size()); ++j) {
          if (set3.find(toLower(temp[j])) == set3.end()) break;
        }
        if (j == static_cast<int>(temp.size())) res.push_back(temp);
      }
    }
    return res;
  }

  inline unsigned char toLower(unsigned char c) { return c < 97 ? c + 32 : c; }
};

int main(int argc, char *argv[]) {
  vector<string> words{"Hello", "Alaska", "Dad", "Peace"};
  Solution s;
  auto res = s.findWords(words);
  for (const auto &ele : res) {
    cout << ele << "\t";
  }
  cout << "\n";
  return 0;
}
