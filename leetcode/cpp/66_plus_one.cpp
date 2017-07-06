#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    int c = 1;
    int len = digits.size();
    int i;
    if (len == 0) return vector<int>{1};
    for (i = len - 1; i >= 0; --i) {
      int remainder = (c + digits[i]) % 10;
      c = (c + digits[i]) / 10;
      digits[i] = remainder;
    }
    if (c != 0) digits.insert(digits.begin(), c);
    return digits;
  }
};

void printVector(vector<int> &v) {
  for (auto &ele : v) {
    cout << ele << "\t";
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> digits{9, 9, 9};
  vector<int> res = s.plusOne(digits);
  printVector(res);
  return 0;
}
