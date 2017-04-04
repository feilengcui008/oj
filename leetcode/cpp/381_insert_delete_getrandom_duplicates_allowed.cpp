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
class RandomizedCollection {
  public:
    /** Initialize your data structure here. */
    RandomizedCollection() = default;

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
      keys_.push_back(val);
      data_.insert(val);
      auto pos = data_.find(val);
      if (pos != data_.end()) {
        return false;
      }
      return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
      auto pos = data_.find(val);
      if (pos != data_.end()) {
        data_.erase(pos);
        // remove one key
        vector<int>::iterator iter = keys_.begin();
        for (; iter != keys_.end(); ++iter) {
          if (*iter == val) break;
        }
        keys_.erase(iter);
        return true;
      }
      return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
      //if (data_.size() == 0) return undefined
      int size = keys_.size();
      std::random_device rd;
      unsigned int index = rd() % size;
      return keys_[index];
    }

  private:
    vector<int> keys_;
    unordered_multiset<int> data_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(int argc, char *argv[])
{
  RandomizedCollection obj;
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
  obj.insert(3);
  obj.remove(3);
  // 3
  cout << obj.getRandom() << endl;
  return 0;
}
