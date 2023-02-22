class Solution {
public:
    int dp[501][501];
    int f(int i, int j, string a, string b)
    {
        if(i >= a.length()) return b.length()-j;
        if(j >= b.length()) return a.length()-i;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j])
        {
            return dp[i][j] = f(i+1, j+1, a, b);
        }
        else{
            int op1 = f(i+1, j, a, b)+1;
            int op2 = f(i, j+1, a, b)+1;
            int op3 = f(i+1, j+1, a, b)+1;
            return dp[i][j] = min({op1, op2, op3});
        }
    }
    
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, word1, word2);
    }
};