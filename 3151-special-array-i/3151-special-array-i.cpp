class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() < 2)
            return true;

        bool isEven = nums[0] % 2 == 0;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] % 2 == 0) == isEven)
                return false;
            isEven = !isEven;
        }
        return true;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();