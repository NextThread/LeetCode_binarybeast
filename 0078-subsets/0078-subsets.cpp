class Solution {
public:
    vector<vector<int>> ans;
    void sub(vector<int> &nums, int ind, vector<int> temp)
    {
        if(ind == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        sub(nums, ind+1, temp);
        temp.push_back(nums[ind]);
        sub(nums, ind+1, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {    
        sub(nums, 0, vector<int> {});
        return ans;
    }
};