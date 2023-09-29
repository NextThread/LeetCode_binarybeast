class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> poo = nums;
        reverse(poo.begin(), poo.end());
        return is_sorted(begin(nums), end(nums)) or is_sorted(poo.begin(), poo.end());
    }
};