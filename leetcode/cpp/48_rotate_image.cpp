#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(n^2), space: O(1)
  void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    if (size <= 1) return;
    for (int i = 1; i < size; ++i) {
      for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < (size + 1) / 2; ++j) {
        swap(matrix[i][j], matrix[i][size - j - 1]);
      }
    }
  }
};
