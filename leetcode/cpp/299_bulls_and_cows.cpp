#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
  string getHint(string secret, string guess) {
    unordered_map<char, vector<int>> um;
    int len = secret.length();
    int bulls = 0;
    int cows = 0;
    // firstly we get the bulls
    // and construct the map
    // time : O(n), space : O(n)
    for (int i = 0; i < len; ++i) {
      if (um.find(secret[i]) == um.end()) {
        um[secret[i]] = vector<int>();
      }
      if (secret[i] == guess[i]) {
        bulls += 1;
      } else {
        um[secret[i]].push_back(i);
      }
    }
    // find cows
    // time : O(n)
    for (int i = 0; i < len; ++i) {
      if (secret[i] != guess[i]) {
        if (um.find(guess[i]) != um.end()) {
          // has a cow
          if (!um[guess[i]].empty()) {
            um[guess[i]].erase(um[guess[i]].begin());
            cows += 1;
          }
        }
      }
    }
    string ret = "";
    string temp;
    s_itoa(bulls, temp);
    ret = ret + temp + "A";
    s_itoa(cows, temp);
    ret = ret + temp + "B";
    return ret;
  }

  int s_itoa(int value, std::string &s) {
    s.clear();
    if (value == 0) {
      s = "0";
      return 1;
    }
    bool flag = true;
    if (value < 0) {
      flag = false;
      value = -value;
    }
    while (value > 0) {
      s.push_back((value % 10) + '0');
      value /= 10;
    }
    if (value != 0) {
      s.push_back(value + '0');
    }
    if (flag == false) {
      s.push_back('-');
    }
    std::reverse(s.begin(), s.end());
    return s.length();
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.getHint(string("1807"), string("7810")) << endl;
  cout << s.getHint(string("1123"), string("0111")) << endl;
  cout << s.getHint(string("011"), string("110")) << endl;
  return 0;
}
