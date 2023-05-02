class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c) {
        if (r == -1 || r == grid.size() || c == -1 || c == grid[0].size() || !grid[r][c] || vis[r][c]) return 0; 
        vis[r][c] = true;
        return grid[r][c] + dfs(grid, vis, r, c + 1) + dfs(grid, vis, r, c - 1) + dfs(grid, vis, r + 1, c) + dfs(grid, vis, r - 1, c);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), result = 0;
        vector<vector<bool>> vis(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(grid, vis, i, j));
            }
        }
        return result;
    }
};