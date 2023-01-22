class Solution {
public:
    
    void dfs(int i, vector<bool>& vis, vector<vector<int>> &adj)
    {
        vis[i] = true;
        for(int it : adj[i])
            if(!vis[it])
                dfs(it, vis, adj);
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        int component = 0;
        if(c.size() < n-1) return -1;
        vector<vector<int>> adj(n);
        vector<bool>vis(n, false);
        for(int i = 0 ; i < c.size() ; i++)
        {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis ,adj);
                component++;
            }
        }
        return component-1;
    }
};