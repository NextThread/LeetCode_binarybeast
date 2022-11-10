class Solution {
public:
  
    int f(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
      if(i == a.length()) return b.length()-j;
      if(j == b.length()) return a.length()-i;
      int ans = 0;
      if(dp[i][j] != -1) return dp[i][j];
      if(a[i] == b[j])
      {
        return f(a, b, i+1, j+1, dp);
      }
      else{
        int insert = 1+f(a, b, i+1, j, dp);
        int del = 1+f(a, b, i, j+1, dp);
        int replace = 1+f(a, b, i+1, j+1, dp);
        ans = min(insert, min(del, replace));
      }
      return dp[i][j] = ans;
    }
  
    int minDistance(string word1, string word2) {
      
      //  Commented part is for Tabulation, else the problem has been solved using memoization.
      
        // int m = word1.size() , n = word2.size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // for(int i = 1 ; i <= m ; i++) dp[i][0] = i;
        // for(int j = 1 ; j <= n ; j++) dp[0][j] = j;
        // for(int i = 1 ; i <= m ; i++)
        //     for(int j = 1 ; j <= n ; j++)
        //         if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
        //         else dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1] , dp[i-1][j])) +1;
        // return dp[m][n];
      vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
      return f(word1, word2, 0, 0, dp);
    }
};