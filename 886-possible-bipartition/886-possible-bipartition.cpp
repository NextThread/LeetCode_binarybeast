class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& edges) {
         vector<vector<int>> adj(N + 1); // adjacency matrix
    vector<int> color(N + 1, 0); 
    vector<bool> explored(N + 1, false); 

    for (auto &edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
 
    queue<int> q;        
    for (int i = 1; i <= N; ++i) {
        if (!explored[i]) {
            color[i] = 1;
            q.push(i);
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (explored[u]) continue;
                
                explored[u] = true;
                for (auto v: adj[u]) {
                    if (color[v] == color[u])
                        return false;

                    color[v] = -color[u];                        
                    q.push(v);
                }
            }
        }
    }
    
    return true;
    }
};