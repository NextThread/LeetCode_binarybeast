class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(i+1, j, grid);
        dfs(i, j+1, grid);
        dfs(i-1, j, grid);
        dfs(i, j-1, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};