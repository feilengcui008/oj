#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    // time: O(n), space: O(n)
    // 细节题...
    string simplifyPath(string path)
    {
      int l = path.length();
      if (l <= 1) return path;
      // find "////a.."
      string res = "";
      int i = 0;
      if (path[i] == '/') {
        res.push_back('/');
      }
      while (i < l && path[i] == '/') i++;

      while (i < l) {
        // find one part a time
        string t = "";
        while (i < l && path[i] != '/') {
          t.push_back(path[i]);
          i++;
        }
        // find a part
        if (t.length() > 0) {
          if (t == "..") {
            // find backward
            int current = res.length() - 2;
            while (current >= 0 && res[current] != '/') current--;
            if (current != (int)res.length() - 2) {
              res = res.substr(0, current + 1);
            } 
          } else {
            if (t != ".") {
              res += t; res.push_back('/');
            }
          }
        }
        // skip this '/'
        i++;
      }
      // maybe get rid of last '/'
      if (res.length() > 1) {
        res = res.substr(0, res.length() - 1);
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.simplifyPath("/a/./b/../../c/") << endl;
  cout << s.simplifyPath("/..") << endl;
  return 0;
}
