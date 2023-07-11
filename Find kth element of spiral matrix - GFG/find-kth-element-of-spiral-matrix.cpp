//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
         // Your code goes here.
         vector<int>s;
         int startRow=0, startCol=0, endRow=n-1, endCol=m-1;
         int totC= m * n, c=0;
         
         
         while(c <  totC){
                 for(int i=startCol; i<=endCol && c < totC; i++){
             s.push_back(a[startRow][i]);
             c++;
         }
         startRow++;
         //increasing value of starting row as nxt time we don't have to print the elements of this row
         for(int i=startRow; i<=endRow && c < totC; i++){
             s.push_back(a[i][endCol]);
             c++;
         }
         endCol--;
         for(int i=endCol; i>=startCol && c < totC; i--){
             s.push_back(a[endRow][i]);
             c++;
         }
         endRow--;
         for(int i=endRow; i>=startRow && c < totC; i-- ){
             s.push_back(a[i][startCol]);
             c++;
         }
         startCol++;
         }
         
         return s[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends