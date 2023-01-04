class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int b1 = INT_MAX, b2 = INT_MAX;
       int profit1 = INT_MIN, profit2 = INT_MIN;
      for(int i = 0 ; i < prices.size() ; i++)
      {
        b1 = min(b1, prices[i]);
        profit1 = max(profit1, prices[i]-b1);
        b2 = min(b2, prices[i]-profit1);
        profit2 = max(profit2, prices[i]-b2);
      }
      return max(profit2, profit1);   
    }
};