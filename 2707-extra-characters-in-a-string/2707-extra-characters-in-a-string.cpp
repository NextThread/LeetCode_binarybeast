class Solution {
public:
    int f(int i, string &s, unordered_map<string, int>& mp, vector<int>& dp) {
        // if index exceeds the size return 0 base case
        if(i >= s.size()) return 0;
        // if already we counted this subproblem then no need to do the whole stuff, use dp array stored result
        if(dp[i] != -1) return dp[i];
        int ans = s.size();
        string st = "";
        for(int idx = i;idx < s.size();idx++) {
            st += s[idx];
            int extraString = st.size();
            // if string is present in map then extracharacter should be 0
            if(mp.find(st) != mp.end()) extraString = 0;
            // calling recursive for other smaller problems
            int nextSearch = f(idx+1, s, mp, dp);
            // storing min ans in ans
            ans = min(ans, extraString+nextSearch);
        }
        // storing dp array for further use of same subproblem
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        vector<int> dp(s.size(), -1);
        // storing the word in dict for checking whether it is present or not
        for(auto dict : dictionary) {
            mp[dict]=1;
        }
        // return using memoisation function f
        return f(0, s, mp, dp);
    }
};