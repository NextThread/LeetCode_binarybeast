class Solution {
public:
    
    int tab(string a, string b) {
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
        
        for(int i = a.size()-1 ; i >= 0 ; i--) 
        {
            for(int j = b.size()-1 ; j >= 0 ; j--) 
            {
                if(a[i] == b[j]) dp[i][j] = 1+ dp[i+1][j+1];
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
        
    }
    
    int f(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
        if(i >= a.length() or j >= b.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = 1+f(i+1, j+1, a, b, dp);
        else return dp[i][j] = max(f(i+1, j, a, b, dp), f(i, j+1, a, b, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return f(0, 0, text1, text2, dp);
        return tab(text1, text2);
    }
};