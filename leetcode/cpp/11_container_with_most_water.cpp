#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int>& height)
    {
      int max = 0;
      int i = 0, j = height.size() - 1;
      while (i < j) {
        int h = height[i] > height[j] ? height[j] : height[i];
        max = (j - i) * h > max ? (j - i) * h : max;
        while (i < j && height[i] <= h) i++;
        while (i < j && height[j] <= h) j--;
      }
      return max;
    }
};


int main(int argc, char *argv[])
{
  vector<int> v{2, 3, 2, 4};
  vector<int> v1{1, 2, 1};
  vector<int> v2{1, 2, 4, 3};
  vector<int> v3{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Solution s;
  cout << s.maxArea(v) << endl;
  cout << s.maxArea(v1) << endl;
  cout << s.maxArea(v2) << endl;
  cout << s.maxArea(v3) << endl;
  return 0;
}
