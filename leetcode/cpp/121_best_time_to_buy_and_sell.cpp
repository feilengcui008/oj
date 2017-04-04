#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) 
    {
      int len = prices.size();
      if (len == 0) return 0;
      int minPrice = prices[0];
      int maxProfit = 0;
      for (int i = 0; i < len; ++i) {
        maxProfit = max(maxProfit, prices[i] - minPrice); 
        if (prices[i] < minPrice)
          minPrice = prices[i];
      }
      return maxProfit;
    }
};
