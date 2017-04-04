#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // O(n^2)
    int findMaxLength(vector<int>& nums)
    {
      int size = nums.size();
      if (size <= 1) return 0;
      vector<int> sums = vector<int>(size);
      sums[0] = nums[0];
      for (int i = 1; i < size; ++i) {
        sums[i] = sums[i - 1] + nums[i];
      }
      return maxLen(sums, nums, 0, size - 1);
    }

    int maxLen(const vector<int> &v, const vector<int> &nums, int i, int j)
    {
      if (i >= j) return 0;
      if ((v[j] - v[i] + nums[i]) * 2 == (j - i + 1)) {
        return j - i + 1;
      }
      int left = maxLen(v, nums, i + 1, j);
      int right = maxLen(v, nums, i, j - 1);
      return left > right ? left : right;
    }
};


int main(int argc, char *argv[])
{
  vector<int> v{0, 1};
  vector<int> v1{0, 1, 0};
  vector<int> v2{0, 0, 0, 1, 1, 1, 0};
  Solution s;
  cout << s.findMaxLength(v) << endl;
  cout << s.findMaxLength(v1) << endl;
  cout << s.findMaxLength(v2) << endl;
  return 0;
}
