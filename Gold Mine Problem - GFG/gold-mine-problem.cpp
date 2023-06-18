//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[51][51]; // 1st
    
    int rec(vector<vector<int>> &M, int n, int m, int i, int j) {
        if(i < 0 or j < 0 or i >= n or j >= m) return 0;
        
        if(dp[i][j] != -1) return dp[i][j]; // 3rd
        
        int rightup = M[i][j] + rec(M, n, m, i-1, j+1);
        
        int right = M[i][j] + rec(M, n, m, i, j+1);
        
        int rightdown = M[i][j] + rec(M, n, m, i+1, j+1);
        
        return dp[i][j] = max({rightup, right, rightdown});
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        memset(dp, -1, sizeof(dp)); // 2nd
        
        int gold = 0;
        for(int i = 0 ; i < n ; i++) {
            int collect = rec(M, n, m, i, 0);
            gold = max(gold, collect);
        }
        
        return gold;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends