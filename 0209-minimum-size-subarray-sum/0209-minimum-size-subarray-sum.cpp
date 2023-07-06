class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0,n=nums.size(),sum=0;
        int ans=n+1;
        while(end < n) {
            sum += nums[end++];
              while(sum >= target) {
                  ans = min(end-start, ans);
                  sum -= nums[start++];
              }
        }
        if(ans == n+1) return 0;
        return ans;
    }
};