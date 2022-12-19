class Solution {
public:
    bool ans = 0;
    void dfs(vector<int>adj[],vector<int>&visited,int src,int end)
    {
        visited[src]=true;
        if(src==end)
        {
            ans=1;
            return;
        }
        for(auto v:adj[src])
        {
            if(!visited[v])
                dfs(adj,visited,v,end);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int>adj[n];
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>visited(n,0);
        dfs(adj,visited,start,end);
        return ans;
    }
};