//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
 vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
         vector<vector<int>> copy;
         copy = graph;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j)copy[i][j]=1;
                if(copy[i][j]==0)copy[i][j]=1e9;
            }
        }
        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(copy[i][k]!=1e9&&copy[k][j]!=1e9){
                        copy[i][j]=min(copy[i][j],copy[i][k]+copy[k][j]);
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                
                if(copy[i][j]==1e9)copy[i][j]=0;
                if(copy[i][j]>0)copy[i][j]=1;
               
            }
        }
        return copy;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends