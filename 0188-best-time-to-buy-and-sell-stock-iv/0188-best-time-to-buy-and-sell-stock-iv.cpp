class Solution {
public:
  
    int f(int ind, int opno, int k, vector<int>& prices, vector<vector<int>> &dp)
    {
      if(ind == prices.size()) return 0;
      if(opno == 2*k) return 0;
      if(dp[ind][opno] != -1) return dp[ind][opno];
      int profit = INT_MIN;
      if(opno%2 == 0)  // buy   sell   buy   sell
      {                //  0     1      2     3  on every even point we can buy
        int lelo = -prices[ind] + f(ind+1, opno+1, k, prices, dp);
        int skip = 0+f(ind+1, opno+0, k, prices, dp);
        profit = max(lelo, skip);
      }
      else
      {
        int becho = prices[ind] + f(ind+1, opno+1, k, prices, dp);
        int skip = 0+f(ind+1, opno+0, k, prices, dp);
        profit = max(becho, skip);
      }
      return profit;
    }
  
  
    int ftabu(int k, vector<int>prices, int n){
    vector<vector<int>> buy(k + 1,vector<int>(n + 1, -1000000000));
    vector<vector<int>> sell(k + 1,vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            buy[j][i] = max(buy[j][i - 1], sell[j - 1][i - 1] - prices[i - 1]);
            sell[j][i] = max(buy[j][i - 1] + prices[i - 1], sell[j][i - 1]);
        }
    }
    
    return sell[k][n];
   }
  
  
    int maxProfit(int k, vector<int>& prices) {
      // vector<vector<int>>dp(prices.size(), vector<int>(2*k, -1)); // this is for memoization, but memo giving tle
        // return f(0, 0, k, prices, dp);
        return ftabu(k, prices, prices.size()); // we are using tabulation
    }
};