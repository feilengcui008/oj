#include <list>
#include <memory>

using namespace std;

struct Node {
  Node(int k, int v) : key(k), value(v) {}
  int key;
  int value;
};

class LRUCache{

  public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) 
    {
      int res = -1;
      for (auto begin = nodes_.begin(); begin != nodes_.end(); ++begin) {
        if ((*begin)->key == key) {
          res = (*begin)->value;
          nodes_.erase(begin);
          nodes_.insert(nodes_.begin(), make_shared<Node>(Node(key, res)));
          break;
        }
      }
      return res;
    }

    void set(int key, int value) 
    {
      for (auto begin = nodes_.begin(); begin != nodes_.end(); ++begin) {
        if ((*begin)->key == key) {
          nodes_.erase(begin);
          nodes_.insert(nodes_.begin(), make_shared<Node>(Node(key, value)));
          return;
        }
      }
      // not exist 
      if (static_cast<int>(nodes_.size()) < capacity_) {
        nodes_.push_back(make_shared<Node>(Node(key, value)));
        return;
      } else {
        nodes_.pop_back();
        nodes_.push_back(make_shared<Node>(Node(key, value)));
      }
    }
  private:
    int capacity_;
    list<shared_ptr<Node>> nodes_;
};
