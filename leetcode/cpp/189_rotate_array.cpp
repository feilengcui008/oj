#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      if (k > n)
        k = k % n;
      exchange(nums, 0, n - k);
      exchange(nums, n - k, k);
      exchange(nums, 0, n);

    }

    void exchange(vector<int>& arr, int start, int len)
    {
      if (len <= 0)
        return;
      int i = start, j = start + len - 1;
      while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
      }
    }
};
