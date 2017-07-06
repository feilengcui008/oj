#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
  // time: O(n), space: O(n)
  int trap(vector<int>& height) {
    int size = height.size();
    vector<int> left(size, 0);
    vector<int> right(size, 0);
    int sum = 0;
    // compute the highest height on the left of i
    // left[i+1] = max{left[i], height[i]}
    for (int i = 1; i < size; ++i) {
      left[i] = max(left[i - 1], height[i - 1]);
    }
    // compute the highest height on the right of i
    // right[j-1] = max{right[j], height[j]}
    for (int j = size - 1; j >= 1; j--) {
      right[j - 1] = max(right[j], height[j]);
    }
    // compute the water of i
    for (int k = 1; k < size - 1; ++k) {
      if (min(left[k], right[k]) > height[k]) {
        sum += (min(left[k], right[k]) - height[k]);
      }
    }
    return sum;
  }

  inline int max(int a, int b) { return a > b ? a : b; }

  inline int min(int a, int b) { return a < b ? a : b; }
};

int main(int argc, char* argv[]) {
  vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> v1{2, 0, 2};
  Solution s;
  cout << s.trap(v) << endl;
  cout << s.trap(v1) << endl;
  return 0;
}
