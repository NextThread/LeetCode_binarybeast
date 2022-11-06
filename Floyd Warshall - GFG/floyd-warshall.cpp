//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	      int i,j,k;

     int n=matrix.size();

     

     for(k=0;k<n;k++){

         vector<vector<int>> m(matrix);

         for(i=0;i<n;i++)

             for(j=0;j<n;j++)

             if(m[i][j]==-1)

             m[i][j]=10000;

         for(i=0;i<n;i++){

             for(j=0;j<n;j++)

             matrix[i][j]=min(m[i][j],m[i][k]+m[k][j]);

         }

         for(i=0;i<n;i++)

             for(j=0;j<n;j++)

             if(matrix[i][j]>=10000)

             matrix[i][j]=-1;

     }

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends