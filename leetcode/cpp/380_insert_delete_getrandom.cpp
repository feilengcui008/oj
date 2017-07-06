#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>

using namespace std;

// since insert and remove need O(1) time,
// we need unordered hashmap, and we use a
// extra vector to store all keys for rand
// access, we just skip the delete ones when
// rand are called.
class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() = default;

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    auto pos = data_.find(val);
    if (pos != data_.end()) {
      return false;
    }
    data_.insert(val);
    keys_.push_back(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    auto pos = data_.find(val);
    if (pos != data_.end()) {
      data_.erase(pos);
      return true;
    }
    return false;
  }

  /** Get a random element from the set. */
  int getRandom() {
    // if (data_.size() == 0) return undefined
    int size = keys_.size();
    std::random_device rd;
    unsigned int index;
    for (;;) {
      index = rd() % size;
      if (data_.find(keys_[index]) != data_.end()) {
        break;
      }
    }
    return keys_[index];
  }

 private:
  vector<int> keys_;
  unordered_set<int> data_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(int argc, char *argv[]) {
  RandomizedSet obj;
  bool param_1 = obj.insert(2);
  // true
  cout << boolalpha << param_1 << endl;
  // 2
  cout << obj.getRandom() << endl;
  obj.insert(3);
  // true
  bool param_2 = obj.remove(2);
  cout << param_2 << endl;
  // 3
  int param_3 = obj.getRandom();
  cout << param_3 << endl;
  return 0;
}
