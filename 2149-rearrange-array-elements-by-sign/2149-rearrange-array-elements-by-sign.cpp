class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0, j = 0 ; i < n and j < n  ; i++, j++)
        {
            while(nums[i] < 0) i++;
            res.push_back(nums[i]);
            while(nums[j] > 0) j++;
            res.push_back(nums[j]);
        }
        return res;
    }
};