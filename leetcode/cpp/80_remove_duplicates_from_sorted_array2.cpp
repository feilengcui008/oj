#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(n), space: O(1)
  int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    if (size <= 2) return size;
    int idx = 2;
    for (int i = 2; i < size; ++i) {
      if (nums[i] != nums[idx - 2]) {
        nums[idx] = nums[i];
        idx++;
      }
    }
    return idx;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> v{1, 1, 1, 1};
  vector<int> v1{1, 1, 1, 2, 2, 3};
  cout << s.removeDuplicates(v) << endl;
  cout << s.removeDuplicates(v1) << endl;
  return 0;
}
