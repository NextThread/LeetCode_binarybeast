class Solution {
public:
  
    void dfs(int src, vector<vector<int>>& isConnected, vector<int>& vis)
    {
     vis[src] = true; // make the starting node as visited
     vector<int>adj; // to make the adjacency matrix
     for(int i = 0 ; i < isConnected.size() ; i++)
     {
       if(isConnected[src][i] == 1) // if it is one that means it has adjacent nodes, so store it in the adjacency list
       {
         adj.push_back(i);
       }
     }
      for(auto it : adj)
      {
        if(!vis[it]) // if not visited, then call dfs
        {
          dfs(it, isConnected, vis);
        }
      }
    }
  
    int findCircleNum(vector<vector<int>>& isConnected) {
      
      // no of times we need to call the dfs, will be our answer, because we have to count how many disjoint are their in our graph
      
      int cnt = 0;
      vector<int>vis(isConnected.size(), false); // visited array, initially filled as false
      for(int i = 0 ; i < isConnected.size() ; i++)
      {
        if(!vis[i])
        {
          cnt++; // increment no of provinces by 1
          dfs(i, isConnected, vis); // call dfs
        }
      }
      return cnt;
    }
};