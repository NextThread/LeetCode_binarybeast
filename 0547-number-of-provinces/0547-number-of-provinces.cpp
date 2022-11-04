class Solution {
public:
  
    void dfs(int src, vector<vector<int>>& isConnected, vector<int>& vis)
    {
     vis[src] = true; 
     vector<int>adj;
     for(int i = 0 ; i < isConnected.size() ; i++)
     {
       int bit = isConnected[src][i];
       if(bit == 1)
       {
         adj.push_back(i);
       }
     }
      for(auto it : adj)
      {
        if(!vis[it])
        {
          dfs(it, isConnected, vis);
        }
      }
    }
  
    int findCircleNum(vector<vector<int>>& isConnected) {
      int cnt = 0;
      vector<int>vis(isConnected.size(), false);
      for(int i = 0 ; i < isConnected.size() ; i++)
      {
        if(!vis[i])
        {
          cnt++;
          dfs(i, isConnected, vis);
        }
      }
      return cnt;
    }
};