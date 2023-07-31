class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int ans) {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j]== 0 or vis[i][j] == true) return 0;
        vis[i][j] = true;
        return 1 + dfs(i+1, j, grid, vis, ans)
        + dfs(i, j+1, grid, vis, ans)
        + dfs(i-1, j, grid, vis, ans)
        + dfs(i, j-1, grid, vis, ans);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int res = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1) {
                    int ans = 0;
                    ans = dfs(i, j, grid, vis, ans);
                    res = max(res, ans);
                }
            }
        }
        return res;
    }
};