//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	#define mod 1000000007

int countWays(int arr[],int ind,int target,vector<vector<int>> &dp)
    {
        
        if(ind<0)
        {
            return target==0;
        }
       
        
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        
        int notTake=countWays(arr,ind-1,target,dp)%mod;
        int take=0;
        if(target>=arr[ind])
        {
            take=countWays(arr,ind-1,target-arr[ind],dp)%mod;
        }
        
        return dp[ind][target] = (take+notTake)%mod;
    }
    
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return countWays(arr,n-1,sum,dp);
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends