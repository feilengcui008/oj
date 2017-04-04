#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
  public:
    // time: O(logn), space: O(1)
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
      int size = intervals.size();      
      if (size <= 0) return vector<Interval>{newInterval};
      // find position
      auto cmp = [newInterval](Interval x) {
        return x.start >= newInterval.start;
      };
      auto pos = find_if(begin(intervals), end(intervals), cmp);
      intervals.insert(pos, newInterval);
      return merge(intervals);
    }

    vector<Interval> merge(vector<Interval>& intervals)
    {
      int size = intervals.size();      
      if (size <= 1) return intervals;
      vector<Interval> res;
      // sort first
      auto cmp = [](Interval l, Interval r) { return l.start < r.start; };
      sort(begin(intervals), end(intervals), cmp);
      // merge
      Interval bg(intervals[0].start, intervals[0].end);
      for (int i = 1; i < size; ++i) {
        if (intervals[i].start > bg.end) {
          res.push_back(bg);
          bg.start = intervals[i].start;
          bg.end = intervals[i].end;
        } else {
          bg.end = intervals[i].end > bg.end ? intervals[i].end : bg.end;
        }
      }
      res.push_back(bg);
      return res;
    }

};

int main(int argc, char *argv[])
{
  vector<Interval> v{
    Interval(1, 3),
    Interval(6, 9),
  };
  Interval itv(2, 5);
  Solution s;
  auto res = s.insert(v, itv);
  for (auto &ele : res) {
    cout << ele.start << "\t" << ele.end << endl;
  }
  return 0;
}
