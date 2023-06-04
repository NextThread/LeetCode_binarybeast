class Solution {
public:
    int dp[501][501];
    int rec(int i, int timer, vector<int>& s) {
        if(i >= s.size()) return 0;
        if(dp[i][timer] != -1) return dp[i][timer];
        int op1 = (s[i]*timer) + rec(i+1, timer+1, s);
        int op2 = 0 + rec(i+1, timer, s);
        return dp[i][timer] = max(op1, op2);
    }
    
    int maxSatisfaction(vector<int>& s) {
        memset(dp, -1, sizeof(dp));
        sort(s.begin(), s.end());
        return rec(0, 1, s);
    }
};