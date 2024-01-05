class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        
        
        vector<int> sums(nums.size(), 0);

            
        for(int i = 0 ; i < nums.size() ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(nums[i] > nums[j] and dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    sums[j] = nums[i];
                }
            }
        }
        
        for(int x : sums) cout << x << ' ';
        
        cout << endl;
        
        return *max_element(dp.begin(), dp.end());
    }
};