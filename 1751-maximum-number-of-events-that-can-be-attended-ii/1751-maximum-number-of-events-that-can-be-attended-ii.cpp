class Solution {

public:
    
    int recur(vector<vector<int>>&dp,int idx,vector<vector<int>>&events,int k)
    {
        if(idx>=events.size() or k==0)
            return 0;
        int i;
        
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        for(i=idx+1;i<events.size();i++)
        {
            if(events[i][0]>events[idx][1])
            {
                break;
            }
        }
        int op1=recur(dp,idx+1,events,k);
        int op2=events[idx][2]+recur(dp,i,events,k-1);
        
        return dp[idx][k]=max(op1,op2);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),[]
            (vector<int>&a,vector<int>&b)
             {
                 if(a[0]==b[0])
                     return a[1]<b[1];
                 return  a[0]<b[0];
             }
            );
        int n=events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return recur(dp,0,events,k);
        
        
    }
};