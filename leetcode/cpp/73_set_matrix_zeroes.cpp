#include <vector>
#include <limits.h>

using namespace std;

class Solution {
  public:
    // time: O(l1^2 * l2^2), space: O(1)
    void setZeroes(vector<vector<int>>& matrix)
    {
      int l1 = matrix.size();
      if (l1 == 0) return;
      int l2 = matrix[0].size();
      if (l2 == 0) return;
      // find a number between [1, l1*l2+1] not in the matrix
      int n; bool found;
      for (n = 1; n <= l1 * l2 + 1; ++n) {
        found = false;
        for (int i = 0; i < l1; ++i) {
          for (int j = 0; j < l2; ++j) {
            if (matrix[i][j] == n) {
              found = true;
            }
          }
        }
        if (found == false) {
          break;
        }
      }
      for (int i = 0; i < l1; ++i) {
        for (int j = 0; j < l2; ++j) {
          if (matrix[i][j] == 0) {
            matrix[i][j] = n;
            for (int k = 0; k < l2; ++k) {
              if (matrix[i][k] != 0) {
                matrix[i][k] = n;
              }
            }
            for (int k = 0; k < l1; ++k) {
              if (matrix[k][j]) {
                matrix[k][j] = n;
              }
            }
          }
        }
      }
      for (int i = 0; i < l1; ++i) {
        for (int j = 0; j < l2; ++j) {
          if (matrix[i][j] == n) {
            matrix[i][j] = 0;
          }
        }
      }
    }
};
