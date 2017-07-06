#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> v;
    int pre = 0;
    int len = nums.size();
    if (len == 0) return v;
    for (int i = 1; i < len; ++i) {
      if (nums[i] != nums[i - 1] + 1) {
        if (pre == i - 1) {
          v.push_back(to_string(nums[pre]));
        } else {
          v.push_back(to_string(nums[pre]) + "->" + to_string(nums[i - 1]));
        }
        pre = i;
      }
    }
    if (pre == len - 1) {
      v.push_back(to_string(nums[pre]));
    } else {
      v.push_back(to_string(nums[pre]) + "->" + to_string(nums[len - 1]));
    }
    return v;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  vector<int> v{1, 2, 3, 5, 6, 9};
  vector<string> vs = s.summaryRanges(v);
  for (auto &ele : vs) {
    cout << ele << endl;
  }
  return 0;
}
