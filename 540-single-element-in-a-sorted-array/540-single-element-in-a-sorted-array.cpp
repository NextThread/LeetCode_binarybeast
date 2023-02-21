class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorr = 0;
        for(auto it : nums) xorr ^= it;
        return xorr;
    }
};