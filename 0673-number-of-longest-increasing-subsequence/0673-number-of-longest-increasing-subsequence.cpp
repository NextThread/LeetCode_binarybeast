class Solution {
public:
    pair<int,int> gmax;
    pair<int,int> helper(const vector<int>& nums, int idx, vector<pair<int,int>>& dp) {
        if (dp[idx].first == -1 && dp[idx].second == -1) {
            pair<int,int> longestlenandcount = {0, 1};

            for (int i=idx+1; i<nums.size();++i){
                if (nums[i] > nums[idx]) {
                    auto res = helper(nums, i, dp);
                    if (res.first > longestlenandcount.first) {
                        longestlenandcount = res;
                    } else if (res.first == longestlenandcount.first) {
                        longestlenandcount.second += res.second;
                    }
                }
            }
 
            longestlenandcount.first++;
            dp[idx] = longestlenandcount;
        }

        if (gmax.first < dp[idx].first) {
            gmax = dp[idx];
        } else if (gmax.first == dp[idx].first) {
            gmax.second += dp[idx].second;
        }

        return dp[idx];
    }

    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size(), {-1, -1});
        gmax = {0, 1};

        for (int i=0;i<nums.size();++i){
            helper(nums, i, dp);
        }

        return gmax.second;
    }
};
