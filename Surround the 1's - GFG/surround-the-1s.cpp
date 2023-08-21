//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
   bool ggs(vector<vector<int> >& matrix,int i,int j,int count){
    int n = matrix.size();
    int m = matrix[0].size();
    
    for(int k = 0; k < 9; k++) {
        int left, right;
        
        if(k < 3){
            left = i - 1;
            if(k%3==0){
                right = j - 1;
            }
            else if(k%3==1){
                right = j;
            }
            else{
                right = j+1;
            }
        }
        else if(k < 6){
            left = i;
            if(k%3==0){
                right = j - 1;
            }
            else if(k%3==1){
                right = j;
            }
            else{
                right = j+1;
            }
        }
        else if(k < 9){
            left = i + 1;
            if(k%3==0){
                right = j - 1;
            }
            else if(k%3==1){
                right = j;
            }
            else{
                right = j+1;
            }
        }
            
        if(left >= 0 && right >= 0 && left < n && right < m){
            if(matrix[left][right] == 0){
                count++;
            }
        }
    }
    
    return (count % 2 == 0 && count !=0);
}

int Count(vector<vector<int> >& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int c = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j]!=1)
                {
                    continue;
                }
            if(ggs(matrix, i, j, 0)){
                c++;
            }
        }
    }
    
    return c;
}


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends