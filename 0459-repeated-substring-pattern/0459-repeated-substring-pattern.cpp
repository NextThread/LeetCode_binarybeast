class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n=s.length();
        vector<int> dp(n,0);
        
        int i=1;
        int j=0;
        
        for(i=1;i<n;)
        {
            if(s[i]==s[j])
            {
                j++;
                dp[i]=j;
                i++;
            }
            else
            {
                if(j!=0)
                {
                    j=dp[j-1];
                }
                else
                {
                    dp[i]=0;
                    i++;
                }
            }
        }
        
        return dp[n-1] && (dp[n-1]%(n-dp[n-1])==0);
    }
};