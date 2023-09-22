class Solution {
public:
    int rec(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
        if(i >= a.size() or j >= b.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j]; // 3rd
        if(a[i] == b[j]) {
            return dp[i][j] = 1 + rec(i+1, j+1, a, b, dp); // 4th
        }
        int op1 = rec(i+1, j, a, b, dp);
        int op2 = rec(i, j+1, a, b, dp);   
        return dp[i][j] = max(op1, op2);
    } 
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(0, 0, s, t, dp);
    }
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int len = longestCommonSubsequence(s, t);
        if(len == s.size()) return true;
        return false;
    }
};