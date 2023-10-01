//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > mat, int n, int m) 
    {
  vector<int>ans;
    if(n==1 || m==1){
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           ans.push_back(mat[i][j]);
        }
       }
    }
    else{
        int i=0,j=0;
        while(i==0 && j<m-1){
            ans.push_back(mat[i][j]);
            j++;
        }
          i=0,j=m-1;
         while(j==m-1 && i<n-1){
            ans.push_back(mat[i][j]);
            i++;
        }
         i=n-1,j=m-1;
         while(i==n-1 && j>=1){
            ans.push_back(mat[i][j]);
            j--;
        }
          i=n-1,j=0;
         while(j==0 && i>=1){
            ans.push_back(mat[i][j]);
            i--;
        }
    }    
        return ans;    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends