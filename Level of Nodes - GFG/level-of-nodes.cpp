//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int n, vector<int> v[], int x) 
	{
	    vector<bool> vis(n, false);
	    queue<pair<int, int>> q;
	    q.push({0, 0});
	    vis[0]=true;
	    while(!q.empty()){
	        int vertex = q.front().first;
	        int level = q.front().second;
	        if (vertex==x) return level;
	        q.pop();
	        for(auto child: v[vertex]){
	            if (vis[child]) continue;
	            q.push({child, level+1});
	            vis[child]=true;
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends