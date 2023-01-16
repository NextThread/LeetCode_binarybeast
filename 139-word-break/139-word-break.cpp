class Solution {
public:
    
    int dp[1001][1001];
    
    bool f(int i, int j, string &s, unordered_set<string> &ust)
    {
        if(ust.find(s.substr(i, j-i+1)) != ust.end()) return true;
        if(i == j) return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool res = false;
        for(int k = i ; k < j ; k++)
        {
            res = res || (f(i, k, s, ust) && f(k+1, j, s, ust));
        }
        return dp[i][j] = res;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>ust;
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        for(int i = 0 ; i < wordDict.size() ; i++)
        {
            ust.insert(wordDict[i]);
        }
        return f(0, n-1, s, ust);
    }
};