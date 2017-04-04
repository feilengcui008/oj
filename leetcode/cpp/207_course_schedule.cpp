#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    // 拓扑排序 
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
      // corner case 
      if (numCourses <= 0) return true;
      int len = prerequisites.size();
      if (len == 0) return true;
      // 入度
      vector<int> book(numCourses, 0);
      // 节点是否已被删除
      vector<bool> status(numCourses, false);
      // 边是否已被删除
      vector<bool> pairStatus(len, false);
      for (int i = 0; i < len; ++i) {
        book[prerequisites[i].second]++;
      }
      for (;;) {
        // 找入度为零且没被删除的
        int i = -1;
        // O(n)
        for (i = 0; i < numCourses; ++i) {
          if (book[i] == 0 && status[i] == false) {
            break;
          }
        }
        // not find 
        if (i == numCourses) break;
        // 删除点
        status[i] = true;
        // 找到，删除边，将临近节点的度减1
        // O(n)
        for (int j = 0; j < len; ++j) {
          if (!pairStatus[j] && prerequisites[j].first == i) {
            book[prerequisites[j].second]--;
            pairStatus[j] = true;
          }
        }
      }
      // check if has cycle
      return !any_of(status.begin(), status.end(), [](bool x) -> bool { return x == false; });
    }
};

int main(int argc, char *argv[])
{
  vector<pair<int, int>> v;
  v.push_back(pair<int, int> { 1, 0 });
  v.push_back(pair<int, int> {0, 1});
  int n = 2;
  Solution s;
  cout << s.canFinish(n, v) << endl;
  return 0;
}
