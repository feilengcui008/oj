#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    vector<int> parts1;
    vector<int> parts2;
    split(version1, string("."), parts1);
    split(version2, string("."), parts2);
    int len1 = parts1.size();
    int len2 = parts2.size();
    while (len1 > 0 && parts1[len1 - 1] == 0) {
      len1--;
    }
    while (len2 > 0 && parts2[len2 - 1] == 0) {
      len2--;
    }
    int small = len1 < len2 ? len1 : len2;
    for (int i = 0; i < small; ++i) {
      if (parts1[i] < parts2[i]) return -1;
      if (parts1[i] > parts2[i]) return 1;
    }
    if (len1 == len2) return 0;
    return len1 > len2 ? 1 : -1;
  }

  /*
     int comparePart(string first, string second)
     {
     int len1 = first.length();
     int len2 = second.length();
     int index1 = 0;
     int index2 = 0;
     for (int i = 0; i < len1; ++i) {
     if (first[i] != '0') break;
     else index1++;
     }
     for (int i = 0; i < len2; ++i) {
     if (second[i] != '0') break;
     else index2++;
     }
     if ((len1 - index1) > (len2 - index2))
     return 1;
     if ((len1 - index1) < (len2 - index2))
     return -1;
     int i;
     for (i = 0; i < (len1 - index1); ++i) {
     if (first[index1 + i] > second[index2 + i])
     return 1;
     if (first[index1 + i] < second[index2 + i])
     return -1;
     }
     return 0;
     }
     */

  void split(const string& src, const string& separator, vector<int>& dest) {
    string substring;
    string::size_type start = 0, index;
    do {
      index = src.find_first_of(separator, start);
      if (index != string::npos) {
        substring = src.substr(start, index - start);
        dest.push_back(atoi(substring.c_str()));
        start = src.find_first_not_of(separator, index);
        if (start == string::npos) return;
      }
    } while (index != string::npos);
    substring = src.substr(start);
    dest.push_back(atoi(substring.c_str()));
  }

  void printVector(vector<string>& v) {
    for (auto& ele : v) {
      cout << ele << endl;
    }
  }
};

int main(int argc, char* argv[]) {
  string s1 = "12.4";
  string s2 = "12.6";
  string s3 = "1.23";
  Solution s;
  cout << s.compareVersion(s1, s1) << endl;
  cout << s.compareVersion(s1, s2) << endl;
  cout << s.compareVersion(s1, s3) << endl;
  cout << s.compareVersion("1.1", "1") << endl;
  cout << s.compareVersion("01", "1") << endl;
  cout << s.compareVersion("1.1", "1.10") << endl;
  cout << s.compareVersion("1.0", "1") << endl;
  cout << s.compareVersion("1", "0") << endl;
  return 0;
}
