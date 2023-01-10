class Solution {
public:
    
    int f(int ind, vector<int> &nums, int half, vector<vector<int>> &dp)
    {
        if(ind >= nums.size()) return false;
        if(half == 0) return true;
        if(half < 0) return false;
        if(dp[ind][half] != -1) return dp[ind][half];
        int takeit = f(ind+1, nums, half-nums[ind], dp);
        int donttakeit = f(ind+1, nums, half, dp);
      return dp[ind][half] = takeit | donttakeit;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int half = sum >> 1;
        vector<vector<int>> dp(nums.size(), vector<int>(half+1, -1));
        return f(0, nums, half, dp);
    }
};