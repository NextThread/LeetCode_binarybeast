class Solution {
    public:
    int dp[51][51][2501];
    int vis[51][51];
    long long rec(vector<vector<int>> &grid, int i, int j, int time) {
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j]) return INT_MAX;
        
        if(i == grid.size()-1 && j == grid[0].size()-1) return time + max(0, grid[i][j]-time);
        
        if(dp[i][j][time] != -1 )return dp[i][j][time];
        
        vis[i][j] = 1;
        
        long long op1, op2, op3, op4;
        
        op1 = rec(grid, i+1, j, time + max(0, grid[i][j]-time));
        op2 = rec(grid, i-1, j, time + max(0, grid[i][j]-time));
        op3 = rec(grid, i, j+1, time + max(0, grid[i][j]-time));
        op4 = rec(grid, i, j-1, time + max(0, grid[i][j]-time));
        
        vis[i][j] = 0;
        
        return dp[i][j][time] = min({op1,op2,op3,op4});
        
    }
    int swimInWater(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof(vis));
        memset(dp, -1, sizeof(dp));
        return rec(grid, 0, 0, 0);
    }
};