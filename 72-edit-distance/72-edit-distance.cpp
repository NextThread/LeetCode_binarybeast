class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i == s.length())
            return t.length() - j;
        if (j == t.length())
            return s.length() - i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return f(i + 1, j + 1, s, t, dp);
        else
        {
            int op1 = 1 + f(i + 1, j + 1, s, t, dp);
            int op2 = 1 + f(i + 1, j, s, t, dp);
            int op3 = 1 + f(i, j + 1, s, t, dp);
            return dp[i][j] = min(op1, min(op2, op3));
        }
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        return f(0, 0, word1, word2, dp);
    }
};