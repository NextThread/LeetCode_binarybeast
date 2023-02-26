class Solution {
public:
    
    int f(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    {
        if(i >= a.length()) return b.length()-j;
        if(j >= b.length()) return a.length()-i;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j])
        {
            return dp[i][j] = f(i+1, j+1, a, b, dp);
        }
        else{
            int op1 = 1 + f(i+1, j, a, b, dp);
            int op2 = 1 + f(i, j+1, a, b, dp);
            int op3 = 1 + f(i+1, j+1, a, b, dp);
            return dp[i][j] = min({op1, op2, op3});
        }
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        return f(0, 0, word1, word2, dp);
    }
};