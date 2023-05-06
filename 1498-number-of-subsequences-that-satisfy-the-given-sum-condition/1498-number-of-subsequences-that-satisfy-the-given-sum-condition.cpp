class Solution {
public:

long long int mod = 1e9+7;

long long int power(long long int p)
{
	long long int temp=0;
    if(p==0)
    {
        return 1;
    }
    temp=power(p/2);
    if(p%2==0)
    {
        return (temp*temp)%mod;
    }
    else
    {
        return (2*(temp*temp)%mod)%mod;
    }
}
    int numSubseq(vector<int>& nums, int t) {
       int n=nums.size();
       long long int ans=0;
       sort(nums.begin(),nums.end());
       int i=0,j=n-1;
       while(i<=j)
       {
           if(nums[i]+nums[j]<=t)
           {
               int p=j-i;
               long long int total=power(p);
               //ans+=pow(2,j-i);
               ans=(ans+total)%mod;
               i++;
           }
           else
           {
               j--;
           }
       }
       return ans % mod;
    }
};