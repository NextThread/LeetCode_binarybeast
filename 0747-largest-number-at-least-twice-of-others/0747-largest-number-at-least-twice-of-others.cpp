class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int cnt = 0;
        int mx = *max_element(nums.begin(), nums.end());
        int ind = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] != mx and nums[i] * 2 > mx) return -1;
            if(nums[i] == mx) ind = i;
        }
        return ind;
    }
};