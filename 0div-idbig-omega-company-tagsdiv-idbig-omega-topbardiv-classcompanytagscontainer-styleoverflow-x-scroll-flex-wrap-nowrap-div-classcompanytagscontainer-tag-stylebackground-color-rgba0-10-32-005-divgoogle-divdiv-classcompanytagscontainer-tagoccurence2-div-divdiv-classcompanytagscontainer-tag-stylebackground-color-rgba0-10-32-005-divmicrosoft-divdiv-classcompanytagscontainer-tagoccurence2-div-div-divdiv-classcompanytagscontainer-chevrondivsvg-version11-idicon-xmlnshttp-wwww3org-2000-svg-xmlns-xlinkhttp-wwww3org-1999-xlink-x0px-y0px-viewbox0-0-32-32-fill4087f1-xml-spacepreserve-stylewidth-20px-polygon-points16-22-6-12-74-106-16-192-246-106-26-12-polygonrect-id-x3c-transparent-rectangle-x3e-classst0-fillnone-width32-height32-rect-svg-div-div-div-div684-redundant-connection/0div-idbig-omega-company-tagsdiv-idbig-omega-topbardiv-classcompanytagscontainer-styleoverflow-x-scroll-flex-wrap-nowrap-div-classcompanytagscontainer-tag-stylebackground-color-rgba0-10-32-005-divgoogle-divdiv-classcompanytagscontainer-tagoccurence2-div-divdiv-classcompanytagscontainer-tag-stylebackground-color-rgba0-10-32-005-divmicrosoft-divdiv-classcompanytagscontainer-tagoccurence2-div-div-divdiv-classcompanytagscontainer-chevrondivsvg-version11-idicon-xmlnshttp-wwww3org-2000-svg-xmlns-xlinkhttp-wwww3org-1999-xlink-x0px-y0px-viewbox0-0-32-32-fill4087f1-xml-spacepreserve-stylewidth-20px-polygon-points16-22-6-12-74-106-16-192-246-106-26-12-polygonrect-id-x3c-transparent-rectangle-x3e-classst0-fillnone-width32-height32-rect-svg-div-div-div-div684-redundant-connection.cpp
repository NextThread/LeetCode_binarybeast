class Solution {
public:
    
    bool dfs(int node, int par, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it, node, adj, vis) == true) return true;
            }
            
            else if(it != par) return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        vector<bool> vis(n+1, false);
        
        for(auto it : edges) {
            fill(begin(vis), end(vis), 0);
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            if(dfs(it[0], -1, adj, vis) == true) return it;
        }
        return {};
    }
};