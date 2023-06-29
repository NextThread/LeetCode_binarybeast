class Solution {
public:
    
    int dp[201][201]; // 1st
    
    int rec(int i, int j, vector<vector<int>>& grid) {
        
        if(i >= grid.size() or j >= grid[0].size()) return INT_MAX;
        
        if(i == grid.size()-1 and j == grid[0].size()-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j]; // 3rd
        
        int right = INT_MAX, down = INT_MAX;
        
        if(j < grid[0].size()-1) right = rec(i, j+1, grid) + grid[i][j]; 
        
        if(i < grid.size()-1) down = rec(i+1, j, grid) + grid[i][j];
        
        return dp[i][j] = min(right, down); // 4th
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        memset(dp, -1, sizeof(dp)); // 2nd
        
        return rec(0, 0, grid);
    }
};