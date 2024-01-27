class Solution {
public:
    int kInversePairs(int n, int k) {
       int dp[n+1][k+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= k; j++){
                if(j == 0) dp[i][j] = 1;
                else
                    for(int p = 0; p <= min(j, i-1); p++)
                        dp[i][j] = (dp[i][j] + dp[i-1][j-p])%1000000007;
            }           
    return dp[n][k];
    }
};