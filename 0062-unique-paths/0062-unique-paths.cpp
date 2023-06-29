class Solution {
public:
    int dp[101][101];
    int rec(int i, int j, int m, int n) {
        if(i < 0 or j < 0 or i > m or j > n) return 0;
        if(i == m and j == n) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int right = rec(i, j+1, m, n);
        int down = rec(i+1, j, m, n);
        return dp[i][j] = right + down;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp);
        return rec(1, 1, m, n);
    }
};