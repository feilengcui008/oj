#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> result;
    result.clear();
    if (rowIndex < 0) return result;
    result.push_back(1);
    if (rowIndex == 0) return result;
    result.push_back(1);
    if (rowIndex == 1) return result;
    for (int i = 2; i <= rowIndex; ++i) {
      iter(result);
      result.insert(result.begin(), 1);
    }
    return result;
  }

  void iter(vector<int> &v) {
    int len = v.size();
    for (int i = 0; i < len - 1; ++i) {
      v[i] = v[i] + v[i + 1];
    }
  }
};

void printVec(vector<int> &v) {
  for (auto &ele : v) {
    cout << ele << "\t";
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  auto res = s.getRow(5);
  printVec(res);
  return 0;
}
