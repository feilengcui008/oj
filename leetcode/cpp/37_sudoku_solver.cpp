#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(k^n * n^2), space: O(1)
  // more efficient way?
  void solveSudoku(vector<vector<char>> &board) {
    if (!isValidSudoku(board)) return;
    vector<vector<vector<char>>> res;
    fillNextDot(board, 0, res);
    if (res.size() > 0) {
      board = res[0];
    }
  }

  void fillNextDot(vector<vector<char>> &board, int i,
                   vector<vector<vector<char>>> &res) {
    int size = board.size();
    bool stop = false;
    // find next dot position
    int m = i, n;
    for (; m < size; ++m) {
      for (n = 0; n < size; ++n) {
        if (board[m][n] == '.') {
          stop = true;
          break;
        }
      }
      if (stop) break;
    }
    if (m == size && n == size) {
      res.emplace_back(move(board));
      return;
    }

    // fill dot
    for (int k = 1; k <= size; ++k) {
      auto b = board;
      b[m][n] = k + '0';
      if (isValidSudoku(b)) {
        fillNextDot(b, m, res);
      }
    }
  }

  bool isValidSudoku(vector<vector<char>> &board) {
    int size = board.size();
    vector<bool> flag(size, false);
    // check rows
    for (int i = 0; i < size; ++i) {
      auto t = flag;
      int j;
      for (j = 0; j < size; ++j) {
        if (board[i][j] != '.' && t[board[i][j] - '1']) break;
        if (board[i][j] != '.') t[board[i][j] - '1'] = true;
      }
      if (j != size) return false;
    }

    // check cols
    for (int j = 0; j < size; ++j) {
      auto t = flag;
      int i;
      for (i = 0; i < size; ++i) {
        if (board[i][j] != '.' && t[board[i][j] - '1']) break;
        if (board[i][j] != '.') t[board[i][j] - '1'] = true;
      }
      if (i != size) return false;
    }

    // check square blocks
    for (int i = 0; i < size; i += 3) {
      for (int j = 0; j < size; j += 3) {
        auto t = flag;
        for (int k = i; k <= i + 2; k++) {
          for (int m = j; m <= j + 2; ++m) {
            if (board[k][m] != '.' && t[board[k][m] - '1']) return false;
            if (board[k][m] != '.') t[board[k][m] - '1'] = true;
          }
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<char>> v{{'.', '.', '9', '7', '4', '8', '.', '.', '.'},
                         {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
                         {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
                         {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
                         {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
                         {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
                         {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
                         {'.', '.', '.', '2', '7', '5', '9', '.', '.'}, };
  Solution s;
  s.solveSudoku(v);
  for (auto &ele : v) {
    for (auto &e : ele) {
      cout << e;
    }
    cout << endl;
  }
  return 0;
}
