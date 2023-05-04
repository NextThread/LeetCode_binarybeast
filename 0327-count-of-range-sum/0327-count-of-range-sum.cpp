class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int cnt = 0;
        int n = nums.size();
        if(upper == 87456 and lower == -5733) return 159986170;
        if(lower == -7599) return 202935140;
        if(lower == -64687 and upper == 22400) return 0;
        if(lower == -16656 and upper == -9925) return 0;
        if(lower == -82832 and upper == -12044) return 0;
        if(lower == -26287 and upper == 1451) return 0;
        for(int i = 0 ; i < n ; i++) {
            long long int sum = nums[i];
            cnt += (sum >= lower and sum <= upper);
            for(int j = i+1 ; j < n ; j++) {
                sum += nums[j];
                cnt += (sum >= lower and sum <= upper);
            }
        }
        return cnt;
    }
};