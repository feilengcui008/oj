#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {

 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    // corner case
    if (n <= 0) return res;
    vector<char> leftStack;
    int leftNum = n;
    int rightNum = n;
    chooseNext(leftNum, rightNum, leftStack, string(""), res);
    return res;
  }

 private:
  // 类似这种生成序列的题一般先考虑递归比较简单
  void chooseNext(int leftNum, int rightNum, vector<char> leftStack,
                  string temp, vector<string> &res) {
    // break condition
    if (leftNum == 0 && rightNum == 0) {
      res.push_back(temp);
      return;
    } else {
      if (leftNum != 0) {
        // we can choose left no matter what
        vector<char> newstack = leftStack;
        string newtemp = temp;
        newstack.push_back('(');
        newtemp.push_back('(');
        chooseNext(leftNum - 1, rightNum, newstack, newtemp, res);
      }
      if (!leftStack.empty()) {
        // we can choose right only if leftStack is not empty
        vector<char> newstack = leftStack;
        string newtemp = temp;
        newstack.pop_back();
        newtemp.push_back(')');
        chooseNext(leftNum, rightNum - 1, newstack, newtemp, res);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> res = s.generateParenthesis(4);
  for (auto &ele : res) {
    cout << ele << endl;
  }
  return 0;
}
