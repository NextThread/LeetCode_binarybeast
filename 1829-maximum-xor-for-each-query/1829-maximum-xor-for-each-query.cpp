class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
         vector<int> result(nums.size());
        
        int maxInt = pow(2, maximumBit) - 1;
        
        int bit = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) bit ^= nums[i];
        
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = bit ^ maxInt;
            bit ^= nums[nums.size() - i - 1];
        }
        
        return result;
    }
};