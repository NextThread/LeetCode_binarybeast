class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = INT_MAX;
        for(auto it : nums) res = min(res, abs(it));
        for(auto it : nums) if(it == res) return res;
        return -res;
    }
};