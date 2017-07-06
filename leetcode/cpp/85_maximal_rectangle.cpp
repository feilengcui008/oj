#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(n^2), space: O(n)
  int maximalRectangle(vector<vector<char>> &matrix) {
    int row = matrix.size();
    if (row == 0) return 0;
    int col = matrix[0].size();
    if (col == 0) return 0;
    vector<int> heights(col, 0);
    for (int i = 0; i < col; ++i) {
      heights[i] = (matrix[0][i] == '1' ? 1 : 0);
    }
    int max = largestRectangleArea(heights), t;
    for (int i = 1; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (matrix[i][j] == '1') {
          heights[j] += 1;
        } else {
          heights[j] = 0;
        }
      }
      t = largestRectangleArea(heights);
      max = t > max ? t : max;
    }
    return max;
  }

  // time: O(n), space: O(1)
  int largestRectangleArea(vector<int> &heights) {
    vector<int> stack;
    heights.push_back(0);
    int size = heights.size(), max = 0;
    for (int i = 0; i <= size; ++i) {
      // 当前bar比栈顶的bar高，那么栈顶的第一个元素是
      // 当前bar的左边第一个比其低的bar所在位置。
      if (stack.empty() || heights[i] >= heights[stack.back()]) {
        stack.push_back(i);
      } else {
        // 当前bar比栈顶的bar低，说明找到了栈顶元素的
        // 右边第一个比其低的bar，计算以栈顶元素为高
        // 的矩形的面积
        int idx = stack.back();
        stack.pop_back();
        int s = heights[idx] * (stack.empty() ? i : i - 1 - stack.back());
        max = s > max ? s : max;
        i--;  // notice here
      }
    }
    return max;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<char>> v{{'0', '1'}, {'0', '1'}};
  Solution s;
  cout << s.maximalRectangle(v) << endl;
  return 0;
}
