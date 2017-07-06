#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
  // time : O(n * m), space : O(1)
  int hIndex(vector<int>& citations) {
    int len = citations.size();
    if (len == 0) return 0;
    int temp;
    for (int i = len; i > 0; --i) {
      temp = 0;
      for (auto&& ele : citations) {
        if (ele >= i) temp++;
      }
      if (temp >= i) {
        return i;
      }
    }
    return 0;
  }

  int hIndex1(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int len = citations.size();
    for (int i = len; i > 0; ++i) {
      if (citations[len - i] >= i) return i;
    }
    return 0;
  }
};

int main(int argc, char* argv[]) {
  vector<int> v{1};
  Solution s;
  cout << s.hIndex(v) << endl;
  cout << s.hIndex1(v) << endl;
  return 0;
}
