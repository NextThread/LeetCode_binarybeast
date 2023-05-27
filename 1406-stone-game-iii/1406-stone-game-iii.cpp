class Solution {
public:
    unordered_map<int, int> dp;
    long dfs(int start, int end, vector<int>& prefix){
        if(start <= end){
            if(dp.count(start) > 0) return dp[start];
            int a = dfs(start + 1, end, prefix);
            int b = dfs(start + 2, end, prefix);
            int c = dfs(start + 3, end, prefix);
            dp[start] = prefix[end] - prefix[start] - min(a, min(b,c));
            return dp[start];
        }
        return 0;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + stoneValue[i];
        }
        int sum = dfs(0, n, prefix);
        if(sum*2 >  prefix[n]) return "Alice";
        if(sum*2 == prefix[n]) return "Tie";
        return "Bob";
    }
};