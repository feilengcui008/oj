#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // time: O(n), space: O(n)
    // 基本思路: 对于每个bar，找到包含此bar且以此bar的高度
    // 作为高的矩形的最大面积，这些最大面积中的最大值即是所求
    // 难点在于如何寻找bar左边第一个比其低的bar和右边第一个比
    // 其低的bar，这里关键是使用到了栈。此题的栈存的顺序有个
    // 特点: 元素的高度是严格递增的，因此对于栈中的每个元素
    // (即每个bar的位置)，都能很容易找到其左边第一个高度比其
    // 低的bar的位置，所以循环遍历的过程是找其右边的第一个比
    // 其低的bar的位置。
    int largestRectangleArea(vector<int>& heights)
    {
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
          int idx = stack.back(); stack.pop_back();
          int s = heights[idx] * (stack.empty() ? i : i - 1 - stack.back());
          max = s > max ? s : max;
          i--; // notice here
        }
      }      
      return max;
    }

    // time: O(nlogn), space: O(1)
    int largestRectangleArea1(vector<int> &heights)
    {
      int size = heights.size();
      if (size <= 1) return size == 0 ? 0 : heights[0];
      return divideAndConquer(heights, 0, heights.size() - 1); 
    }

    int divideAndConquer(vector<int> &heights, int i, int j)
    {
        if (i == j) return heights[i];
        int m = i + (j - i) / 2, l, r, max;
        // left part
        l = divideAndConquer(heights, i, m);
        // right part
        r = divideAndConquer(heights, m+1, j);
        // update max
        max = l > r ? l : r;
        // middle part including m and m+1 bar
        int idx1 = m, idx2 = m + 1, h = heights[idx1] > heights[idx2] ? heights[idx1] : heights[idx2];
        // 如何证明这种两边扩散的方法的正确性?
        while (idx1 >= i && idx2 <= j) {
          int t = heights[idx1] > heights[idx2] ? heights[idx2] : heights[idx1];
          h = t < h ? t : h; 
          max = (idx2 - idx1 + 1) * h > max ? (idx2 - idx1 + 1) * h : max;
          if (idx1 == i) {
            idx2++;
          } else if (idx2 == j) {
            idx1--;
          } else {
            if (heights[idx1-1] > heights[idx2+1]) idx1--;
            else idx2++;
          }
        }
        return max;
    }

    // time: O(n^2), space: O(1)
    // TLE...
    int largestRectangleArea2(vector<int>& heights)
    {
      int size = heights.size();
      if (size <= 1) return size == 0 ? 0 : heights[0];
      vector<int> largest;
      for (int i = 0; i < size; ++i) {
        largest.push_back(heights[i]);
      }
      // 算出以每个bar作为结尾的矩形的最大面积，并求这些最大
      // 面积的最大值
      for (int i = 0; i < size; ++i) {
        // find backward
        int l = heights[i], k = i - 1;
        while (k >= 0) {
          if (heights[k] == 0) break;
          if (heights[k] < l) {
            l = heights[k];
          }
          int s = l * (i - k + 1);
          if (s > largest[i]) {
            largest[i] = s;
          }
          k--;
        }
      }
      return *max_element(largest.begin(), largest.end());
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  vector<int> v{2, 1, 5, 6, 2, 3};
  vector<int> v1{2, 1, 2};
  cout << s.largestRectangleArea(v) << endl;
  cout << s.largestRectangleArea2(v1) << endl;
  return 0;
}
