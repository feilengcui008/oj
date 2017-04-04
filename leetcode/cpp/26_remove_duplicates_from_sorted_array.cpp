#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // time: O(n), space: O(1)
    int removeDuplicates(vector<int>& nums)
    {
      int size = nums.size();
      if (size <= 1) return size;
      int index = 1;
      for (int i = 1; i < size; ++i) {
        if (nums[i] > nums[index - 1]) {
          nums[index] = nums[i];
          index++;
        }
      }
      nums.resize(index);
      return index;
    }
};

int main(int argc, char *argv[])
{
  vector<int> v{1, 1, 2};
  Solution s;
  cout << s.removeDuplicates(v) << endl;
  for (auto &ele : v) {
    cout << ele << "\t";
  }
  cout << endl;
  return 0;
}
