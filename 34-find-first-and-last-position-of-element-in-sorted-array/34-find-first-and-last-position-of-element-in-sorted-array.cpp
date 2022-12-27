class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while(lo <= hi)
        {
            if(nums[lo] == target && nums[hi] == target) return {lo, hi};
            if(nums[lo] < target) lo++;
            if(nums[hi] > target) hi--;
        }
        return {-1, -1};
    }
};