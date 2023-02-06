class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> a, b;
        for(int i = 0 ; i < n ; i++)
        {
            a.push_back(nums[i]);
        }
        for(int i = n ; i < nums.size() ; i++)
        {
            b.push_back(nums[i]);
        }
        vector<int>res;
        for(int i = 0 ; i < n ; i++)
        {
            res.push_back(a[i]);
            res.push_back(b[i]);
        }
        return res;
    }
};