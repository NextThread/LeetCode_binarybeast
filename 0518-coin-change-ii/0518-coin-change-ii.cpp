class Solution {
public:
    vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int n, int amount)
    {
        if(n==0)
            return 0;
        if(amount == 0)
        {
            return 1;
        }
        if(dp[n][amount] != -1)
        {
            return dp[n][amount];
        }
        if(coins[n-1] > amount)
        {
            dp[n][amount] = coinChange(coins, n-1, amount);
            return dp[n][amount];
        }
        dp[n][amount] = coinChange(coins, n, amount-coins[n-1]) + coinChange(coins, n-1, amount);
        return dp[n][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) {
            return 1;
        }
        if(n==0)
          return 0;
        
        dp.resize(n+2,vector<int>(amount+2,-1));
        
        dp[n][amount] = coinChange(coins, n, amount);
        return dp[n][amount];
        
    }
};