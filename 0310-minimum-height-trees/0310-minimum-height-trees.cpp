class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // Base case: only one node
        if(n==1) return vector<int>{0};
        
        // graph adjacency list of nodes
        vector<vector<int>>graph(n);
        
        // degree count of nodes
        vector<int>degree(n,0);
        
        // populate graph adjacency list and degree count of nodes
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            graph[a].push_back(b);
            graph[b].push_back(a);
            
            degree[a]++;
            degree[b]++;
        }
        
        queue<int>Q;
        
        // push degree 1 nodes (leaf nodes) in to queue 
        for(int i=0;i<n;i++)
            if(degree[i]==1)Q.push(i);

        // MHT root nodes
        vector<int>res;
        
        // run BFS until queue is empty 
        while(!Q.empty())
        {
            int n = Q.size();
            
            // clear root nodes 
            res.clear();
            
            // perform level order traverse
            while(n--)
            {
                int node = Q.front();
                Q.pop();
                
                // add current in to root node vector
                res.push_back(node);
                
                // process neighbour nodes
                for(int i=0;i<graph[node].size();i++)
                {
                    // decrease degree of neighbour nodes
                    degree[graph[node][i]]--;
                    
                    // push leaf nodes in to queue
                    if(degree[graph[node][i]]==1)
                    {
                        Q.push(graph[node][i]);
                    }
                }
            }
        }
        
        // root nodes of MHT
        return res;
    }
};