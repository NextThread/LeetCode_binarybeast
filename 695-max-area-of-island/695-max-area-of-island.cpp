class Solution {
public:
    int vis[51][51];
    int cnt = 0;
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or vis[i][j] == 1 or grid[i][j] == 0) return;
        vis[i][j] = 1;
        cnt += 1;
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int n = grid.size();
        int m = grid[0].size();
        memset(vis, -1, sizeof(vis));
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                    maxarea = max(maxarea, cnt);
                    cnt = 0;
                }
            }
        }
        return maxarea;
    }
};