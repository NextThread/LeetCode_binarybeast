class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(int x : nums) sign *= (x == 0) ? 0 : ((x < 1) ? -1 : 1);
        return (sign < 0) ? -1 : ((sign > 0) ? 1 : 0);
    }
};