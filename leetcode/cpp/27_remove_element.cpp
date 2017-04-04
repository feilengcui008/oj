#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    // time: O(n*k), space: O(1)
    int removeElement(vector<int>& nums, int val) 
    {
      // from back to front 
      int len = nums.size();
      if (len == 0) return 0;
      int end = len;
      int i = len - 1;
      // notice we should change both i and end
      while (i >= 0) {
        if (nums[i] == val) {
          // calculate steps
          int step = 1;
          while (i - step >= 0) {
            if (nums[i - step] != nums[i]) break;
            step++;
          }
          //remove 
          for (int j = i + 1; j < end; ++j) {
            nums[j - step] = nums[j];
          }
          i -= step;
          end = end - step;
          if (end == 0) break;
        } else {
          i--;
        }
      }
      nums.resize(end);
      return end;
    }
};

int main(int argc, char **argv) 
{
  vector<int> v{1};
  vector<int> v1{3, 2, 2, 3};
  vector<int> v2{3, 3};
  vector<int> v3{2, 3, 3};
  Solution s;
  cout << s.removeElement(v, 1) << endl;
  for (auto ele : v) {
    cout << ele << endl;
  }
  cout << endl;
  cout << s.removeElement(v1, 3) << endl;
  for (auto ele : v1) {
    cout << ele << endl;
  }
  cout << endl;
  cout << s.removeElement(v2, 3) << endl;
  for (auto ele : v2) {
    cout << ele << endl;
  }
  cout << endl;
  cout << s.removeElement(v3, 3) << endl;
  for (auto ele : v3) {
    cout << ele << endl;
  }
}
