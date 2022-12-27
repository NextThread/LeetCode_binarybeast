class Solution {
public:
    int f(int ind, vector<int> coins, int amount, vector<vector<int>>& dp)
    {
        if((ind < 0 && amount > 0) || amount < 0) return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        if(amount == 0) return 1;
        return dp[ind][amount] = f(ind, coins, amount-coins[ind], dp) + f(ind-1, coins, amount, dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return f(n-1, coins, amount, dp);
    }
};