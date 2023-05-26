class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(int x : nums) {
            if(x > 0) pos++;
            else if(x < 0) neg++;
        }
        return max(pos, neg);
    }
};