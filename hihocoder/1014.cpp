#include <iostream>
#include <string>
#include <vector>

// Trie tree

using namespace std;

struct Node{
  int num;
  char val;
  bool end;
  vector<Node *> children;
  Node(char c) :
    val(c), 
    num(0), 
    end(false), 
    children(vector<Node *>(26, NULL)) {}
};

class Tree
{
  public:
    Tree() : root(new Node(' ')) {}
    ~Tree() {}
    // 插入新字符串
    void insert(string &str)
    {
      int len = str.length();
      if (len > 0) {
        _insert(str, root, 0, len);
      }
    }

    // 得到字符串出现次数
    int getNum(string &str)
    {
      Node *p = root;
      for (int i = 0; i < (int)str.length(); ++i) { 
        if (p->children[str[i] - 'a']) {
          p = p->children[str[i]-'a'];
        } else {
          return 0;
        }
      }
      return p->num;
    }

  private:
    Node *root;
    void _insert(string &str, Node *root, int pos, int size){
      // 递归结束条件
      if (pos == size) {
        root->num++;
        root->end = true;
        return;
      }
      root->num++;
      // 获取插入位置
      int index = str[pos] - 'a';
      // 根据插入位置是否已存在节点分别插入
      if (root->children[index]) {
        _insert(str, root->children[index], pos + 1, size);
      } else {
        root->children[index] = new Node(str[pos]);
        _insert(str, root->children[index], pos + 1, size);
      }
    }
};


int main(int argc, char const *argv[])
{
  Tree t;
  int count;
  string str;
  cin >> count;
  while (count) {
    cin >> str;
    t.insert(str);
    count--;
  }
  cin >> count;
  while (count) {
    cin >> str;
    cout << t.getNum(str) << endl;
    count--;
  }
  return 0;
}
