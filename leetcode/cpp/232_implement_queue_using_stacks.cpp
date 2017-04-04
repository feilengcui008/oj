#include <stack>

using namespace std;

class Queue {
  public:
    // Push element x to the back of queue.
    void push(int x) 
    {
      if (current_ == 0) {
        first_.push(x);
      } else {
        while (!second_.empty()) {
          first_.push(second_.top());
          second_.pop();
        }
        first_.push(x);
        current_ = 0;
      }
    }

    // Removes the element from in front of queue.
    void pop(void) 
    {
      if (current_ == 0) {
        while (!first_.empty()) {
          second_.push(first_.top());
          first_.pop();
        }
        second_.pop();
        current_ = 1;
      } else {
        second_.pop();
      }
    }

    // Get the front element.
    int peek(void) 
    {
      int res;
      if (current_ == 0) {
        while (!first_.empty()) {
          second_.push(first_.top());
          first_.pop();
        }
        current_ = 1;
        res = second_.top();
      } else {
        res = second_.top();
      }
      return res;
    }

    // Return whether the queue is empty.
    bool empty(void) 
    {
      return first_.empty() && second_.empty();
    }
  private:
    int current_;
    stack<int> first_;
    stack<int> second_;
};
