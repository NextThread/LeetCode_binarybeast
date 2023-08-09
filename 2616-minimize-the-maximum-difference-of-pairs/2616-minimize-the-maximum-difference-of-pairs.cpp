class Solution {
    bool good(int x, vector<int> &nums, int p) {
        int cnt = 0, n = nums.size();
        for(int i=0; i<n-1; i++) {
            if(nums[i + 1] - nums[i] <= x) cnt++, i++;
        }
        return cnt >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int s = 0, e = 1e9, ans;
        while(s <= e) {
            int m = (s + e) / 2;
            if(good(m, nums, p)) e = m - 1, ans = m;
            else s = m + 1;
        }
        return ans;
    }
};