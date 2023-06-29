//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int rec(int i, int j, int arr[]) {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int minopera = INT_MAX;
        for(int k = i ; k < j ; k++) {
            int op = arr[i-1] * arr[k] * arr[j] + rec(i, k, arr) + rec(k+1, j, arr);
            minopera = min(minopera, op);
        }
        return dp[i][j] = minopera;
    }

    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof dp);
        return rec(1, N-1, arr);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends