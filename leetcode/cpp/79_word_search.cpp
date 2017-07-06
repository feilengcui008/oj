#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  // time: O(m*n*k), space: O(m*n)
  bool exist(vector<vector<char>> &board, string word) {
    int row = board.size();
    if (row == 0) return false;
    int col = board[0].size();
    if (col == 0) return false;
    if (word.length() == 0) return false;
    unordered_map<char, bool> um;
    for (auto &ele : word) {
      um[ele] = true;
    }
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (um.find(board[i][j]) != um.end() && board[i][j] == word[0]) {
          auto b = board;
          if (bfs(b, i, j, word, 0)) return true;
        }
      }
    }
    return false;
  }

  bool bfs(vector<vector<char>> &board, int i, int j, string &word, int k) {
    int row = board.size();
    int col = board[0].size();
    // cross boundary
    if (k == (int)word.length() - 1) return true;

    board[i][j] = '.';
    // check all positions surrounding current position
    auto up = i > 0 && board[i - 1][j] != '.' && board[i - 1][j] == word[k + 1];
    auto down =
        i < row - 1 && board[i + 1][j] != '.' && board[i + 1][j] == word[k + 1];
    auto left =
        j > 0 && board[i][j - 1] != '.' && board[i][j - 1] == word[k + 1];
    auto right =
        j < col - 1 && board[i][j + 1] && board[i][j + 1] == word[k + 1];
    if (up) {
      auto b = board;
      if (bfs(b, i - 1, j, word, k + 1)) return true;
    }
    if (down) {
      auto b = board;
      if (bfs(b, i + 1, j, word, k + 1)) return true;
    }
    if (left) {
      auto b = board;
      if (bfs(b, i, j - 1, word, k + 1)) return true;
    }
    if (right) {
      auto b = board;
      if (bfs(b, i, j + 1, word, k + 1)) return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<char>> v{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'},
                         {'A', 'D', 'E', 'E'}};
  vector<vector<char>> v11{{'a'}};
  vector<vector<char>> v22{{'a', 'b'}, {'c', 'd'}};
  vector<vector<char>> v33{{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'},
                           {'A', 'D', 'E', 'E'}};
  auto v1 = v;
  auto v2 = v;
  string s1 = "ABCCED";
  string s2 = "SEE";
  string s3 = "ABCB";
  cout << s.exist(v, s1) << endl;
  cout << s.exist(v1, s2) << endl;
  cout << s.exist(v2, s3) << endl;
  cout << s.exist(v11, "a") << endl;
  cout << s.exist(v22, "abcd") << endl;
  cout << s.exist(v33, "ABCESEEEFS") << endl;
  return 0;
}
