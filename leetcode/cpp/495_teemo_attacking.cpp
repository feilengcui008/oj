#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // time: O(n), space: O(1)
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
      int size = timeSeries.size();
      if (size == 0) return 0;
      int n = duration, begin, end, pre_end;
      for (int i = 1; i < size; ++i) {
        begin = timeSeries[i];
        end = timeSeries[i] + duration - 1;
        pre_end = timeSeries[i - 1] + duration - 1;
        if (begin > pre_end) {
          n += duration;
        } else {
          n += (end - pre_end);
        }
      }
      return n;
    }
};


int main(int argc, char *argv[])
{
  vector<int> v{1, 2};
  vector<int> v1{1, 4};
  vector<int> v2{1, 2, 3, 4, 5};
  Solution s;
  cout << s.findPoisonedDuration(v, 2) << endl;
  cout << s.findPoisonedDuration(v1, 2) << endl;
  cout << s.findPoisonedDuration(v2, 5) << endl;
  return 0;
}
