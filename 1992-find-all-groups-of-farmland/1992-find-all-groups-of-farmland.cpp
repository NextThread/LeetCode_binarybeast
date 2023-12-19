class Solution {
public:
        // go with dfs
        // starting cell while calling the dfs will be the first two answer
        // and take max during each call for both i and j, that will be the next two answer
    bool vis[301][301];
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    pair<int, int> dfs(vector<vector<int>> &land, int i, int j) {
        vis[i][j] = true;
        pair<int, int> res  = {i, j};
        for(auto it: dirs) {
            int x = i + it[0];
            int y = j + it[1];
            if(x < 0 or y < 0 or x >= land.size() or y >= land[0].size() or vis[x][y] or land[x][y] != 1)
                continue;
            pair<int, int> ans = dfs(land, x, y);
            res.first = max(res.first, ans.first);
            res.second = max(res.second, ans.second);
        }
        return res;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        memset(vis, false, sizeof(vis));
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] and land[i][j] == 1) {
                    pair<int, int> p = dfs(land, i, j);
                    ans.push_back({i, j, p.first, p.second});
                }
            }
        }
        return ans;
    }
};