#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<string>> solveNQueens(int n)
    {
      vector<vector<string>> res;
      auto r = queens(n, n);
      string s(n, '.');
      for (auto &ele : r) {
        vector<string> t;
        for (auto &e : ele) {
          s[e] = 'Q';
          t.push_back(s);
          s[e] = '.';
        } 
        res.push_back(t);
      }
      return res;
    }

    vector<vector<int>> queens(int board_size, int level)
    {   
      if (level <= 1) {
        if (level == 0) return vector<vector<int>>();
        vector<vector<int>> v;
        for (int i = 0; i < board_size; i++) {
          v.push_back(vector<int>{i});
        }
        return v;
      }
      auto res = queens(board_size, level-1);
      vector<vector<int>> v;
      for_each(res.begin(), res.end(), [&v, board_size, level](vector<int> ele) {
        for(int i = 0; i < board_size; i++) {
          //check new combinatiton
          bool flag = true;
          for (int j = 0; j < level - 1; j++) {
            if(ele[j] == i || (j + 1 - level) == (ele[j] - i) || (j + 1 - level) == -(ele[j] - i)) {
              flag = false;
            }
          }
          if (flag == true) {
            vector<int> v1(ele.begin(), ele.end());
            v1.push_back(i);
            v.push_back(v1);
          } 
        }
      });
      return v;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  auto res = s.solveNQueens(4);
  for (auto &ele : res) {
    for (auto &e : ele) {
      cout << e << endl;
    }
    cout << "=======" << endl;
  }
  return 0;
}
