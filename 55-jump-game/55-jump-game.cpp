class Solution {
public:
    bool canJump(vector<int>& nums) {
     int ind = 0;
    for (int reach = 0; ind < nums.size() && ind <= reach; ++ind)
        reach = max(ind + nums[ind], reach);
    return ind == nums.size();
    }
};