class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int n, int m, int k, int prev, vector<vector<vector<int>>>& dp)
    {
        // base case when arr length is covered:
        if(n == 0)
        {
            if(k == 0) return 1;
            else return 0;
        }

        if(dp[n][k][prev] != -1) return dp[n][k][prev];

        int ans = 0;
        for(int i=1; i<=m; i++)
        {
            if(k > 0 && i > prev) ans = ( ans + solve(n-1, m, k-1, i, dp)) % mod; // curr element is greater than previous and also k is greater than 0
            else if(i <= prev) ans = ( ans + solve(n-1, m, k, prev, dp)) % mod;
        }

        return dp[n][k][prev] = ans % mod;
    }

    int solve2(int N, int M, int K)
    {
        vector<vector<vector<int>>> dp (N+1, vector<vector<int>> (K+1, vector<int> (M+1, 0)));

        // base case handle:
        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=K; j++)
            {
                for(int k=0; k<=M; k++)
                {
                    if(i == 0 && j == 0)
                    {
                        dp[i][j][k] = 1;
                    }
                }
            }
        }

        for(int n=1; n<=N; n++)
        {
            for(int k=0; k<=K; k++)
            {
                for(int prev=M; prev>=0; prev--)
                {
                    int ans = 0;
                    for(int i=1; i<=M; i++)
                    {
                        if(k > 0 && i > prev) ans = ( ans + dp[n-1][k-1][i]) % mod; // curr element is greater than previous and also k is greater than 0
                        else if(i <= prev) ans = ( ans + dp[n-1][k][prev]) % mod;
                    }

                    dp[n][k][prev] = ans;
                }
            }
        }

        return dp[N][K][0];
    }

    int numOfArrays(int n, int m, int k) {
        if(k > m) return 0; // as no of increament in cost can be when there are atleast k nos in m
        // vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (k+1, vector<int> (m+1, -1)));
        // return solve(n, m, k, 0, dp) % mod;

        return solve2(n, m, k);
    }
};