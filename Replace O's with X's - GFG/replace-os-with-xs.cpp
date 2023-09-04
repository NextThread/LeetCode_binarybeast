//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int r[4]={-1, 0, 1, 0};
    int c[4]={0, 1, 0, -1};
    void dfs(int i, int j, int n, int m, vector<vector<char>>& mat, vector<vector<bool>>& vis){
       vis[i][j]=true;
        for(int k=0; k<4; ++k){
            int ni=i+r[k];
            int nj=j+c[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && mat[ni][nj]=='O' && !vis[ni][nj]){
                dfs(ni, nj, n, m, mat, vis);
            }
        }
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if((i==0 || i==n-1 || j==0 || j==m-1) && mat[i][j]=='O' && !vis[i][j]){
                    dfs(i, j,n, m, mat, vis);
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(mat[i][j]=='O' && !vis[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends