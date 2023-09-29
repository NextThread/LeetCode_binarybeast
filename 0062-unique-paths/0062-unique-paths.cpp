class Solution {
public:
    
    int dp[101][101];
    
    int rec(int i, int j, int m, int n) {
        if(i > m or j > n) return 0;
        if(i == m and j == n) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int op1 = rec(i+1, j, m, n);
        int op2 = rec(i, j+1, m, n);
        return dp[i][j] = op1+op2;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp);
        return rec(1, 1, m, n);
    }
};