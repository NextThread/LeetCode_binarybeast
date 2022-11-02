//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
             vector<int>row(n,0);
            vector<int>col(m,0);
            
            for(int i = 0 ; i < enemy.size() ; i++){
                row[enemy[i][0]-1] = -1;
                col[enemy[i][1]-1] = -1;
            }
            
            
            int maxRow = 0;
            int maxCol = 0;
            int cntRow = 0;
            int cntCol = 0;
            
            for(int i = 0 ; i < n ; i++){
                if(row[i]!=-1){
                    cntRow++;
                }
                else{
                    cntRow = 0;
                }
                maxRow = max(maxRow,cntRow);
            }
            
            for(int i = 0 ; i < m ; i++){
                if(col[i]!=-1){
                    cntCol++;
                }
                else{
                    cntCol = 0;
                }
                maxCol = max(maxCol,cntCol);
            }
            
            return maxRow*maxCol;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends