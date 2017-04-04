#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    //way one
    bool containsDuplicate(vector<int>& nums) 
    {
      unordered_map<int, bool> um;
      for (const auto &ele : nums) {
        if (um.find(ele) != um.end())
          return true;
        um[ele] = true;
      }
      return false;
    }
    //way two 
    //sort fist
};

int main(int argc, char *argv[])
{
  Solution s;
  vector<int> v{ 1, 2, 3, 4, 5, 5, 3 };
  cout << boolalpha << s.containsDuplicate(v) << endl;
  return 0;
}
