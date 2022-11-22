#define f(i, a, b) for(int i = a ; i <= b ; i++);
class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        dp[n] = INT_MAX;
        for(int i = 1 ; i*i <= n ; i++) {
            dp[n] = min(dp[n], solve(n-(i*i), dp)+1);
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector <int> dp(n+1, -1);
        int ans = solve(n, dp);
        return ans;
    }
};