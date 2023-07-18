//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
		  int f(int i, int j, string &a, string &b, vector<vector<int>> &dp)
	    {
	        if(i >= a.length() or j >= b.length()) return 0;
	        if(dp[i][j] != -1) return dp[i][j];
	        if(a[i] == b[j] and  i != j) return 1+f(i+1, j+1, a, b, dp);
	        int op1 = 0 + f(i+1, j, a, b, dp);
	        int op2 = 0 + f(i, j+1, a, b, dp);
	        return dp[i][j] = max(op1, op2);
	    }
	
		int LongestRepeatingSubsequence(string str){
		    vector<vector<int>> dp(str.length()+1, vector<int>(str.length()+1, -1));
		    return f(0, 0, str, str, dp);
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends