class Solution {
  public:
    bool isPowerOfFour(int num) 
    {
      return withoutLoop2(num);
    }

    bool withoutLoop1(int num)
    {
      if (num <= 0 || (num & (num - 1))) return false;
      return (num % 3 == 1) ? true : false; 
    }
    bool withoutLoop2(int num)
    {
      return !(num & (num - 1)) && 0x55555555;
    }

    bool directSolution(int num) 
    {
      if (num <= 0) return false;
      while (num != 0) {
        if (num == 1) return true;
        if (num % 4 != 0) break;
        num = num >> 2;
      }
      return false;
    }
};
