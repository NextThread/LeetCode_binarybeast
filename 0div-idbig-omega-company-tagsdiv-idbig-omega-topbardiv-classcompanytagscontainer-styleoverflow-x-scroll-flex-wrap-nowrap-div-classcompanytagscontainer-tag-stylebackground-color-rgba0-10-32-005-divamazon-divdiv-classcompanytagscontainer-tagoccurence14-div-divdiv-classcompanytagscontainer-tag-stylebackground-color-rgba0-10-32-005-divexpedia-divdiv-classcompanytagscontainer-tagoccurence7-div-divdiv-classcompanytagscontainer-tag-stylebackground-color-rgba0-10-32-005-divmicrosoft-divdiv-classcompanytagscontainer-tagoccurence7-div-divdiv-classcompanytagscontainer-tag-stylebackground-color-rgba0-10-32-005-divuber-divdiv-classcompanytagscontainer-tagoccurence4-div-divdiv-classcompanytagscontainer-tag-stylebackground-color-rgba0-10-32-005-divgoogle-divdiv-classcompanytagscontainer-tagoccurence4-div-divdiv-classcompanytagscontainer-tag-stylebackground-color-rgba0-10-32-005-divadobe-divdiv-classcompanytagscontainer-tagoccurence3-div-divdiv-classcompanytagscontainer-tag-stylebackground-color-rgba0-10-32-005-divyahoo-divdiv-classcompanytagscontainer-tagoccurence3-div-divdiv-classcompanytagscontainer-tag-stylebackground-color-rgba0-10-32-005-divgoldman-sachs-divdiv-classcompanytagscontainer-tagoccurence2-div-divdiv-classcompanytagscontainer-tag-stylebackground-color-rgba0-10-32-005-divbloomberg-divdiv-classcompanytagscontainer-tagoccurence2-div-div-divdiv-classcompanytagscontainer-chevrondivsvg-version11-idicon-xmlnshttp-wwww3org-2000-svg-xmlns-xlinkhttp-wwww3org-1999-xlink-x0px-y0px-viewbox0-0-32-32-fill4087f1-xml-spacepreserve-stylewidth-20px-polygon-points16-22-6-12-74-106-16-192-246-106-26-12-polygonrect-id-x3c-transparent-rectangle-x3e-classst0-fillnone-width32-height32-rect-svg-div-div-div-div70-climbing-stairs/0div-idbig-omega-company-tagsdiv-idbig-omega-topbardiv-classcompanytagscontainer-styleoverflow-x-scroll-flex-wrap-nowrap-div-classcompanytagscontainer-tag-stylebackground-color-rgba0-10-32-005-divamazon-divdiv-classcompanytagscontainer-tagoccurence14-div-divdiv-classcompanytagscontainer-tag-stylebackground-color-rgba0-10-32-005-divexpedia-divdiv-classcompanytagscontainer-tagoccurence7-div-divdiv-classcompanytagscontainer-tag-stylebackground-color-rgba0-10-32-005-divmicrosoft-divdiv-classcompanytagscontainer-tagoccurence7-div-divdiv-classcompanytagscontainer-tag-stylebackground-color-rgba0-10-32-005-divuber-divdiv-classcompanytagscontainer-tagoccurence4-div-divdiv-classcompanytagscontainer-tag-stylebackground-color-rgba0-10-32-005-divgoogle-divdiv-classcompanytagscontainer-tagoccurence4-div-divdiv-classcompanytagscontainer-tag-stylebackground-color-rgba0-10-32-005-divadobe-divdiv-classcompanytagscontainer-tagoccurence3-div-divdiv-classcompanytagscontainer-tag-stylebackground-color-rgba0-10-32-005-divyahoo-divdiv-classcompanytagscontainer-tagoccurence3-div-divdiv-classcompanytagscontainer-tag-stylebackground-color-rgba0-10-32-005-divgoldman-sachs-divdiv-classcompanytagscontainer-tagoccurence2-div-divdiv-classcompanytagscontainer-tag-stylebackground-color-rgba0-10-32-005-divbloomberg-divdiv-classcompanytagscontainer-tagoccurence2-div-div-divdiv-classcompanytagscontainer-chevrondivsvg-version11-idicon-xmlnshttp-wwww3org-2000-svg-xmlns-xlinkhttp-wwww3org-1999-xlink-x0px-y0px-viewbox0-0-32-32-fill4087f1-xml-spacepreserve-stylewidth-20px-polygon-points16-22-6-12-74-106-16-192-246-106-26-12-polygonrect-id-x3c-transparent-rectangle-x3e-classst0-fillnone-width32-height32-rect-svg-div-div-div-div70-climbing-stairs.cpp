class Solution {
public:
    
    int solve(int n, vector<int> &dp) {
        if(n <= 2) return n;
        
        if(dp[n] != -1) return dp[n];
        
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        
        return dp[n];
    }
    
    int climbStairs(int n) {
        
        // if(n == 3) return 3;
        if(n <= 2) return n;
        
        vector<int> dp(n+1, -1);
        
        return solve(n, dp);
    }
};