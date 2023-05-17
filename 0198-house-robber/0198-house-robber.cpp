class Solution {
public:
    int dp[100];
    int f(int i, vector<int> &nums) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + f(i+2, nums);
        int notpick = 0 + f(i+1, nums);
        return dp[i] = max(pick, notpick);
    }
    
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
       return f(0, nums); 
    }
};