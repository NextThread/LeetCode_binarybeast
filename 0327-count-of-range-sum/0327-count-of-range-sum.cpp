class Solution {
public:
    int f(vector<long>& sum, int lower, int upper, int low, int high) {
        if(high - low <= 1) return 0;
        int mid = (low+high) >> 1;
        int m = mid, n = mid, count =0;
        count = f(sum, lower, upper, low, mid) + f(sum, lower, upper, mid, high);
        for(int i = low ; i < mid ; i++) {
            while(m < high && sum[m] - sum[i] < lower) m++;
            while(n < high && sum[n] - sum[i] <= upper) n++;
            count += n - m;
        }
        inplace_merge(sum.begin()+low, sum.begin()+mid, sum.begin()+high);
        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long int> sum(nums.size() + 1, 0);
        for(int i = 0 ; i < nums.size() ; i++) sum[i+1] = sum[i]+nums[i];
        return f(sum, lower, upper, 0, nums.size()+1);
    }
};