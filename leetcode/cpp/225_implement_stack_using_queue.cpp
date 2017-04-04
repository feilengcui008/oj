#include <queue>

using namespace std;

class Stack {
  public:
    // Push element x onto stack.
    void push(int x) 
    {
      if (current_ == 0) {
        first_.push(x);
      } else {
        second_.push(x);
      }
    }

    // Removes the element on top of the stack.
    void pop() 
    {
      if (current_ == 0) {
        int len1 = first_.size();
        for (int i = 0; i < len1 - 1; ++i) {
          second_.push(first_.front());
          first_.pop();
        }
        first_.pop();
        current_ = 1;
      } else {
        int len2 = second_.size();
        for (int i = 0; i < len2 - 1; ++i) {
          first_.push(second_.front());
          second_.pop();
        }
        second_.pop();
        current_ = 0;
      }
    }

    // Get the top element.
    int top() 
    {
      int res;
      if (current_ == 0) {
        int len1 = first_.size();
        for (int i = 0; i < len1 - 1; ++i) {
          second_.push(first_.front());
          first_.pop();
        }
        res = first_.front();
        second_.push(first_.front());
        first_.pop();
        current_ = 1;
      } else {
        int len2 = second_.size();
        for (int i = 0; i < len2 - 1; ++i) {
          first_.push(second_.front());
          second_.pop();
        }
        res = second_.front();
        first_.push(second_.front());
        second_.pop();
        current_ = 0;
      }
      return res;
    }


    // Return whether the stack is empty.
    bool empty() 
    {
      return first_.empty() && second_.empty();
    }

  private:
    int current_;
    queue<int> first_;
    queue<int> second_; 

};
