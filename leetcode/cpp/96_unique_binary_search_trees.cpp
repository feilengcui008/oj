#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int numTrees(int n)
    {
      if (n <= 1) return 1;
      if (n == 2) return 2;
      if (um.find(n) != um.end()) return um[n];
      // partition by each element
      int s = 0;
      for (int i = 1; i <= n; ++i) {
        s += numTrees(i - 1) * numTrees(n - i);
      }
      um[n] = s;
      return s;
    }
  private:
    unordered_map<int, int> um;
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.numTrees(2) << endl;
  cout << s.numTrees(3) << endl;
  return 0;
}
