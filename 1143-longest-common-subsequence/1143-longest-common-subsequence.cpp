class Solution {
public:    
    int longestCommonSubsequence(string a, string b) {
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
};