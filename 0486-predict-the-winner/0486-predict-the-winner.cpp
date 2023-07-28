class Solution {
public:
	int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
		if(i>j) return 0;
		if(dp[i][j]!=-1) return dp[i][j];
		int a= nums[i]+ min(f(i+2,j,nums,dp),f(i+1,j-1,nums,dp));
		int b= nums[j]+ min(f(i+1,j-1,nums,dp),f(i,j-2,nums,dp));
		return dp[i][j]=max(a,b);
	}

	bool PredictTheWinner(vector<int>& nums) {
		int n=nums.size();
		vector<vector<int>> dp(n,vector<int>(n,-1));
		int p1=f(0,n-1,nums,dp);  
		int p2=accumulate(nums.begin(),nums.end(),0)-p1;
		return p1>=p2;
	}
};