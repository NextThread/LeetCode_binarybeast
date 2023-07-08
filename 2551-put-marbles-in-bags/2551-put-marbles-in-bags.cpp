class Solution {
public:
    int n; 

vector<vector<long long>> dp;
 vector<vector<long long>> dp1;
long long solve (vector<int> &a, int i, int k)
{
    if(k==0) return INT_MIN;
    if(i==n-1 && k==1) return a[i];
    else if(i==n-1 && k>1) return INT_MIN;
    
     if(dp[i][k]!=-1) return dp[i][k];
    if(i==0)
    {
       
        return  dp[i][k]= a[i]+max(solve(a,i+1,k-1)+a[i]+a[i+1],solve(a,i+1,k));

    }
    
    
   
    return dp[i][k]= max(solve(a,i+1,k-1)+a[i]+a[i+1],solve(a,i+1,k));
  
}

long long solve1 (vector<int> &a, int i, int k)
{
     if(k==0) return INT_MAX;
    if(i==n-1 && k==1) return a[i];
    else if(i==n-1 && k>1) return INT_MAX;
   
      if(dp1[i][k]!=-1) return dp1[i][k];
    if(i==0)
    {
       
        return dp1[i][k]= a[i]+min(solve1(a,i+1,k-1)+a[i]+a[i+1],solve1(a,i+1,k));
       
    }
    
    
    //long long res=0;
   
    return dp1[i][k]= min(solve1(a,i+1,k-1)+a[i]+a[i+1],solve1(a,i+1,k));
  
    
}
// long long putMarbles(vector<int>& a, int k) 
// {
//     n=a.size();
//     dp.resize( n+1 , vector<long long>( n+1,-1) );
//      dp1.resize( n+1 , vector<long long>( n+1,-1) );

//     cout<<solve(a,0,k)<<"  "<<solve1(a,0,k)<<endl;
//     return solve(a,0,k)-solve1(a,0,k);
    long long putMarbles(vector<int>& a, int k) 
{
    int n=a.size();
    if (k==1|k==n) return 0;
    
    vector<long long> v;
    for(int i=0; i<n-1; i++)
    {
        v.push_back(a[i]+a[i+1]);
    }
    
    sort(v.begin(),v.end());
    
    long  long maxi=0;
    long long mini=0;
    
    for(int i=0; i<k-1; i++) // to devide marbels in to k groups we need to pplace k
    {
        maxi+=v[n-2-i];
        mini+=v[i];
    }
    
    return maxi-mini;
    
    
}


};