class Solution {
public:
int dp[100005][2][3];
int mod=1e9+7;
long long int solve(int n,int a,int l)
{
    if(a==2 || l==3)
        return 0;
    if(n==0)
        return 1;
    if(dp[n][a][l]!=-1)
        return dp[n][a][l];
    long long int ans=0;
    ans=solve(n-1,a,0)%mod;//present
    ans=(ans+solve(n-1,a+1,0)%mod)%mod;//absent
    ans=(ans+solve(n-1,a,l+1)%mod)%mod;//late
    return dp[n][a][l]=ans;
}
int checkRecord(int n)
{
    memset(dp,-1,sizeof(dp));
    return solve(n,0,0);
}
};