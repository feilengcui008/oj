#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(n^2), space: O(n)
  // any more efficient way?
  bool isValidSudoku(vector<vector<char>>& board) {
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

int main(int argc, char* argv[]) {
  Solution s;
  return 0;
}
