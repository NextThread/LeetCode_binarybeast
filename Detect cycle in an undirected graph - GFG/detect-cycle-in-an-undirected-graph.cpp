//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

     bool dfs(int v, vector<int> adj[],vector<bool>&vis,int parent){
         vis[v] = 1;
        for(int neighbour:adj[v]) {
            if(!vis[neighbour]) {
                if(dfs(neighbour,adj,vis,v))  return true;
            }
            else if(parent !=neighbour) return true;
        }
        return false;
     }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,0);
        
        for(int i = 0 ; i < V ; i++) {
        if(!vis[i]) {
            if(dfs(i, adj, vis, -1)) return true; 
           }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends