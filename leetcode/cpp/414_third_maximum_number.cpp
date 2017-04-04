#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
  public:
    int thirdMax(vector<int>& nums)
    {
      int size = nums.size();
      int first = numeric_limits<int>::min();
      for (int i = 0; i < size; ++i) {
        if (nums[i] > first) {
          first = nums[i];
        }
      }
      int second = numeric_limits<int>::min();
      for (int i = 0; i < size; ++i) {
        if (nums[i] != first && nums[i] > second) {
          second = nums[i];
        }
      }
      int third = numeric_limits<int>::min();
      bool flag = false;
      for (int i = 0; i < size; ++i) {
        if (nums[i] != first && nums[i] != second) {
          if (nums[i] == numeric_limits<int>::min()) {
            flag = true;
          }
          if (nums[i] > third) {
            third = nums[i];
          }
        }
      }
      if (third != numeric_limits<int>::min() || flag) {
        return third;
      }
      return first;
    }
};


int main(int argc, char *argv[])
{
  vector<int> v{2, 2, 3, 1};
  vector<int> v1{1, 2};
  vector<int> v2{1, 2, -2147483648};
  Solution s;
  cout << s.thirdMax(v) << endl;
  cout << s.thirdMax(v1) << endl;
  cout << s.thirdMax(v2) << endl;
  return 0;
}
