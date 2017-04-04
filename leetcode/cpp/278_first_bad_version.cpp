bool isBadVersion(int version);

class Solution {
  public:
    // modified version of binary search
    // time : O(logn), space : O(1)
    int firstBadVersion(int n) 
    {
      int begin = 1, end = n;
      int middle;
      while (begin <= end) {
        middle = begin + (end - begin) / 2;
        if (isBadVersion(middle)) {  
          // first bad version or the pre is not bad version
          if (middle == 1 || !isBadVersion(middle - 1)) {
            return middle;
          } else {
            end = middle - 1;
          }
        } else {
          begin = middle + 1;
        }
      }
      return -1;
    }
};
