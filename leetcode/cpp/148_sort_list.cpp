#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *sortList(ListNode* head) 
    {
      if (head == nullptr || head->next == nullptr)
        return head;
      int i = 0;
      ListNode *temp = head;
      while (temp != nullptr) {
        i++;
        temp = temp->next;
      }
      //std::cout << "the number of list nodes is : " << i << std::endl;
      listMergeSort(&head, 0, i - 1);
      return head;
    }

    // 注意传入指针的指针，因为我们要修改root
    void listMerge(ListNode **root, int l, int middle, int r)
    {
      //std::cout << "in listMerge " << " l: " << l << " middle: " << middle << " r: " << r << std::endl;
      ListNode *leftBegin = *root;
      ListNode *rightBegin = *root;
      // dummyroot.next is the new root pointer to be returned  
      ListNode dummyNode(0); 
      ListNode *dummyroot = &dummyNode;
      // count middle in the left part
      int leftCount = middle - l + 1;
      int rightCount = r - middle;
      // save the pointer 
      ListNode *pre = *root;
      for (int i = 0; i < l - 1; ++i) {
        pre = pre->next;
      }
      ListNode *end = *root;
      for (int i = 0; i <= r; ++i) {
        end = end->next;
      }
      // std::cout << "i am here" << std::endl;
      // first we move the two head pointers to the specific positions 
      for (int i = 0; i < l; ++i) {
        leftBegin = leftBegin->next;
      }
      for (int i = 0; i <= middle; ++i) {
        rightBegin = rightBegin->next;
      }

      // do the merge 
      for (;;) {
        if (leftCount <= 0 || rightCount <= 0)
          break;
        if (leftBegin->val < rightBegin->val) {
          dummyroot->next = leftBegin;
          leftBegin = leftBegin->next;
          dummyroot = dummyroot->next;
          leftCount--;
        } else {
          dummyroot->next = rightBegin;
          rightBegin = rightBegin->next;
          dummyroot = dummyroot->next;
          rightCount--;
        }
      }
      // at least one half finished 
      //std::cout << "leftCount : " << leftCount << std::endl;
      //std::cout << "rightCount : " << rightCount << std::endl;
      if (leftCount > 0) {
        while (leftCount > 0) {
          dummyroot->next = leftBegin;
          dummyroot = dummyroot->next;
          leftBegin = leftBegin->next;
          leftCount--;
        }
      } 
      if (rightCount > 0) {
        while (rightCount > 0) {
          dummyroot->next = rightBegin;
          dummyroot = dummyroot->next;
          rightBegin = rightBegin->next;
          rightCount--;
        }
      }

      // reconnect front
      if (l != 0) {
        pre->next = dummyNode.next;
      }
      // reconnect back 
      dummyroot->next = end;

      // l == 0, replace root 
      if (l == 0) *root = dummyNode.next; 
      //std::cout << "after listMerge: " << " l: " << l << " r: " << r << " " << (*root)->val << std::endl;
    }

    void listMergeSort(ListNode **root, int l, int r) 
    { 
      //std::cout << "in listMergeSort : " << " l: " << l << " r: " << r << std::endl;
      if (l < r) {
        int middle = (l + r) / 2;
        listMergeSort(root, l, middle);
        listMergeSort(root, middle + 1, r);
        listMerge(root, l, middle, r);
      }
    }
};

int main(int argc, char *argv[])
{
  ListNode *n0 = new ListNode(1);
  ListNode *n1 = new ListNode(2);
  ListNode *n2 = new ListNode(6);
  ListNode *n3 = new ListNode(2);
  ListNode *n4 = new ListNode(4);
  ListNode *n5 = new ListNode(5);
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  Solution s;
  /*
     std::cout << "==========" << std::endl;
     ListNode *n00 = new ListNode(3);
     ListNode *n11 = new ListNode(2);
     ListNode *n22 = new ListNode(4);
     n00->next = n11;
     n11->next = n22;
     Solution s;
     */

  /* 
  // there are some bugs 
  while (n00 != nullptr) {
  std::cout << n00->val << std::endl;  
  n00 = n00->next;
  }
  */
  ListNode *res = s.sortList(n0);
  while (res != nullptr) {
    std::cout << res->val << std::endl;  
    res = res->next;
  }
  return 0;
}
