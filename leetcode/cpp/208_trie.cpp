#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct TrieNode {
  public:
    int num;   // how many strings contain this prefix
    char val;  // char value
    bool end;  // is end of a string 
    vector<TrieNode *> children;
    TrieNode() : val(' '), num(0), end(false), 
    children(vector<TrieNode *>(26, nullptr)) {};
    TrieNode(char value) : val(value), num(0), 
    end(false), children(vector<TrieNode *>(26, nullptr)) {};
};

class Trie {
  public:
    Trie() : root(new TrieNode()) {};
    ~Trie() { freeNode(root); }
    void freeNode(TrieNode *n)
    {
      if(n == nullptr)
        return;
      int i;
      for (i = 0; i < 26; i++) {
        if(n->children[i] != nullptr)
          freeNode(n->children[i]);
      }
      delete n;
    }

    void insert(string word)
    {
      int len = word.length();
      if (len == 0) return;
      _insert(word, root, 0, len);
    }

    bool search(string word)
    {
      int size = word.length();
      int i = 0;
      if(size == 0) return true;
      TrieNode *p = root;
      while (i < size && p->children[word[i]-'a'] != nullptr) {
        // do not turn around these two lines...
        p = p->children[word[i]-'a'];
        i++;
      }
      if(i == size && p->end == true)
        return true;
      else 
        return false;
    }

    bool startsWith(string word)
    {
      int size = word.length();
      int i = 0;
      if (size == 0)
        return true;
      TrieNode *p = root;
      while (i < size && p->children[word[i]-'a'] != nullptr) {
        p = p->children[word[i]-'a'];
        i++;
      }
      if (i == size)
        return true;
      else 
        return false;
    }

    // get how many times for a string appears in this trie tree 
    int getNum(string &str)
    {
      TrieNode *p = root;
      int i;
      for (i = 0; i < (int)str.length(); ++i) {
        if (p->children[str[i] - 'a']) {
          p = p->children[str[i] - 'a'];
        } else {
          return 0;  // if trie contains str, then never get here
        }
      }
      return p->num;
    }

  private:
    TrieNode *root;

    // recursively insert char 
    void _insert(string &str, TrieNode *root, int pos, int size)
    {
      if (pos == size) {
        root->num++;
        root->end = true;
        return;
      }
      // increase the appear number
      root->num++;
      int index = str[pos] - 'a';
      //if already exists 
      if (root->children[index]) { 
        _insert(str, root->children[index], pos + 1, size);
      } else {
        root->children[index] = new TrieNode(str[pos]);
        _insert(str, root->children[index], pos + 1, size);
      }
    }
};

int main(int argc, char *argv[])
{
  /*
     Trie t;
     int count;
     string str;
     cin >> count;
     while (count){
     cin >> str;
     t.insert(str);
     count--;
     }
     cin >> count;
     while (count){
     cin >> str;
     cout << t.getNum(str) << endl;
     count--;
     }
     */

  cout << "search and startsWith tests:\n";
  Trie t1;
  string s1 = "abcdef";
  string s2 = "abc";
  string s3 = "abc";
  t1.insert(s1);
  cout << t1.search(s2) << "\n";
  cout << t1.startsWith(s3) << "\n";

}
