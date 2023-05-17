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
        // memset(dp, -1, sizeof(dp));
       // return f(0, nums); 
        dp[0] = nums[0];
        if(nums.size() == 1) return dp[0];
        dp[1] = max(nums[0], nums[1]);
        if(nums.size() == 2) return dp[1];
        for(int i = 2 ; i < nums.size() ; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];
    }
};