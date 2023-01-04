class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(begin(nums), end(nums));
    }
};