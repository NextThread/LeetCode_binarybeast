class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int ans = 0;
        vector<map<long long, int>> dp(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long int)nums[i] - nums[j];
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += cnt + 1;
                ans += cnt;
            }
        }
        return ans;
    }
};