#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    int res = 0;
    for (auto &ele : nums) {
      res ^= ele;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v{1, 1, 2, 2, 3};
  Solution s;
  std::cout << s.singleNumber(v) << std::endl;
  v = {1};
  std::cout << s.singleNumber(v) << std::endl;
  return 0;
}
