class Solution {
public:
    void dfs(vector<vector<int>> &g,set<pair<int,int>> &is,int i,int j)
    {
         
        if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]!=1||is.count({i,j}))
            return;
        
        is.insert({i,j});
        g[i][j]=2;
        dfs(g,is,i+1,j);
        dfs(g,is,i-1,j);
        dfs(g,is,i,j+1);
        dfs(g,is,i,j-1);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        set<pair<int,int>> is1,is2;
        
        int n=grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {  
                if(grid[i][j]==1&&!vis[i][j])
                {
                    if(f==0)
                    {   
                        dfs(grid,is1,i,j);
                        f++;
                    }
                    else
                        dfs(grid,is2,i,j);
                 }
             }
        }
        int ans=INT_MAX;
     
        for(auto i :is1)
        for(auto j :is2) 
            ans=min(ans,(abs(i.first - j.first) + abs(i.second - j.second)-1));
        return ans;
    }
};
