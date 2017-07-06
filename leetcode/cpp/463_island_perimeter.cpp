#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(n^2), space: O(1)
  int islandPerimeter(vector<vector<int>>& grid) {
    int size = grid.size(), sum = 0;
    if (size == 0) return 0;
    int col = grid[0].size();
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == 1) {
          sum += 4;
          if (i - 1 >= 0 && grid[i - 1][j]) sum -= 1;
          if (i + 1 <= size - 1 && grid[i + 1][j]) sum -= 1;
          if (j - 1 >= 0 && grid[i][j - 1]) sum -= 1;
          if (j + 1 <= col - 1 && grid[i][j + 1]) sum -= 1;
        }
      }
    }
    return sum;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> v{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  vector<vector<int>> v1{{0, 1}, };
  Solution s;
  cout << s.islandPerimeter(v) << endl;
  cout << s.islandPerimeter(v1) << endl;
  return 0;
}
