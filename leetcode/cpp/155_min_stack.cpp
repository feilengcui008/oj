#include <iostream>
#include <vector>

using namespace std;

class MinStack {
 public:
  void push(int x) {
    if (v1_.size() == 0) {
      v1_.push_back(x);
      v2_.push_back(x);
      return;
    }
    int temp = getMin();
    if (x < temp) {
      v2_.push_back(x);
    } else {
      v2_.push_back(temp);
    }
    v1_.push_back(x);
  }

  void pop() {
    v1_.pop_back();
    v2_.pop_back();
  }

  int top() {
    int size = v1_.size();
    return v1_[size - 1];
  }

  int getMin() {
    int size = v1_.size();
    return v2_[size - 1];
  }

 private:
  vector<int> v1_;
  vector<int> v2_;
};

int main(int argc, char *argv[]) {
  MinStack s;
  s.push(-2);
  cout << s.top() << "-" << s.getMin() << "\n";
  s.push(0);
  cout << s.top() << "-" << s.getMin() << "\n";
  s.push(-1);
  cout << s.top() << "-" << s.getMin() << "\n";
  cout << s.top() << "\n";
  s.pop();
  cout << s.getMin() << "\n";
  return 0;
}
