#include <vector>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
  Data* data;

 public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    hasPeeked_ = false;
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (!hasPeeked_) {
      peekedValue_ = Iterator::next();
      hasPeeked_ = true;
    }
    return peekedValue_;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    if (!hasPeeked_) {
      return Iterator::next();
    }
    hasPeeked_ = false;
    return peekedValue_;
  }

  bool hasNext() const { return hasPeeked_ || Iterator::hasNext(); }

 private:
  int peekedValue_;
  int hasPeeked_;
};
