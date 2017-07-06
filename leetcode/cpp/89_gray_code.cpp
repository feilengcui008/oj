#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // time: O(2^n), space: O(2^n)
  vector<int> grayCode(int n) {
    if (n == 0) return vector<int>{0};
    if (n == 1) return vector<int>{0, 1};
    vector<int> temp = grayCode(n - 1), res;
    for (int i = 0; i < (int)temp.size(); ++i) {
      res.push_back(temp[i]);
    }
    for (int i = (int)temp.size() - 1; i >= 0; --i) {
      res.push_back((1 << (n - 1)) | temp[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  auto res = s.grayCode(3);
  for (auto ele : res) {
    cout << ele << endl;
  }
  return 0;
}
