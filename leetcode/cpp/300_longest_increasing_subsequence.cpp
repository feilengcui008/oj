#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) 
  {
    int len = nums.size();
    // corner case 
    if (len <= 1) return len;
    vector<int> s(len, 1);
    int max = 1;
    // 状态转移 : s[n] = max { s[i] + 1 (if nums[n] > nums[i] for i = 0~n-1) else s[i] , i = 0, 1, ..., n - 1} 
    for (int i = 1; i < len; ++i) {
      int tempMax = s[i];
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (s[j] + 1 > tempMax) tempMax = s[j] + 1;
        } 
      }
      //cout << "tempmax:" << tempMax << endl;
      s[i] = tempMax;
      if (tempMax > max) max = tempMax;
    }
    return max;
  }
};

int main(int argc, char **argv) 
{
  vector<int> v {10, 9, 2, 5, 3, 7, 101, 18};
  //v = {1,3,6,7,9,4,10,5,6};
  Solution s;
  cout << s.lengthOfLIS(v) << endl;
}