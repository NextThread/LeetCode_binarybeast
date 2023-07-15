class Solution {
public:
    int solve(vector<vector<int>>&dp, vector<vector<int>>& events, int n, int pos, int k)
{
        int i;
        
        if(pos >= n || k == 0)
            return 0;
        
        if(dp[pos][k] != -1)
            return dp[pos][k];
        
        // finding the next event which we can attend
        for(i = pos + 1; i < n; i++)
            if(events[i][0] > events[pos][1])
                break;
        
       return dp[pos][k] = max(solve(dp, events, n, pos+1, k), events[pos][2] + solve(dp, events, n, i, k-1));

    }
    
    int maxValue(vector<vector<int>>& events, int k) 
    {
        int n = events.size();
        sort(events.begin(), events.end());
        
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        
        return solve(dp, events, n, 0, k);
    }
};