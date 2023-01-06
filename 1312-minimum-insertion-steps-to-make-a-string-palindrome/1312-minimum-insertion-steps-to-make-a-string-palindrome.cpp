class Solution {
public:
    int minInsert(string& s,int i,int j,vector<vector<int>>& dp) {
        if(i >= j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = minInsert(s,i+1,j-1,dp);
        int dec1 = minInsert(s, i+1, j, dp)+1;
        int dec2 = minInsert(s, i, j-1, dp)+1;
        return dp[i][j] = min(dec1,dec2);
    } 
    int minInsertions(string s) {
        vector<vector<int>>dp (s.length(), vector<int>(s.length(),-1));
        return minInsert(s, 0, s.length()-1, dp);
    }
};