class Solution {
  public:
    int uniquePaths(int n, int m) 
    {
      // notice overflow
      long c = 1;
      int N = n + m - 2;
      int k = n - 1;
      // N*(N-1)*...*(N-k+1) / k!
      for (int i = k - 1, j = 1; i >= 0; --i, ++j) {
        // multiply big numbers but divide small numbers first
        c *= (N - i);
        c /= j;
      }
      return (int)c;
    }
};
