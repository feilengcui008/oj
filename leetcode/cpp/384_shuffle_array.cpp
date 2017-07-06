#include <vector>
#include <random>
#include <iostream>

using namespace std;

class Solution {
 public:
  Solution(vector<int> nums) { data_ = nums; }

  vector<int> reset() { return data_; }

  vector<int> shuffle() {
    vector<int> res = data_;
    int len = res.size();
    for (int i = 0; i < len; ++i) {
      int rand = random(0, len - i - 1);
      swap(res[i], res[rand]);
    }
    return res;
  }

  int random(int begin, int end) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(begin, end);
    return distribution(generator);
  }

 private:
  vector<int> data_;
};

int main(int argc, char *argv[]) {
  default_random_engine generator;
  uniform_int_distribution<int> int_distribution(0, 6);
  uniform_real_distribution<float> real_distribution(0, 6);
  uniform_real_distribution<double> double_distribution(0, 6);
  int n = 100;
  for (int i = 0; i < n; ++i) {
    cout << int_distribution(generator) << " -- "
         << real_distribution(generator) << " -- "
         << double_distribution(generator) << endl;
  }
  return 0;
}
