class Solution {
public:
    
    // 
    
    int f(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp) {
        if(i >= nums1.size() or j >= nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(nums1[i] == nums2[j]) return dp[i][j] = 1+f(i+1, j+1, nums1, nums2, dp);
        else return dp[i][j] = max(f(i+1, j, nums1, nums2, dp), f(i, j+1, nums1, nums2, dp));
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return f(0, 0, nums1, nums2, dp);
    }
};