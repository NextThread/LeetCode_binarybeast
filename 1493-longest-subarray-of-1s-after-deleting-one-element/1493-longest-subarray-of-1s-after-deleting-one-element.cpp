class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ones=0, zero=0;
        int n=nums.size(), i=0, j=0, res=0;
        
        while(j<n){
            if(nums[j]==0) zero++;
            else ones++;
            
            if(zero<2) res=max(res, ones);
            else{
                while(zero>1){
                    if(nums[i]==0) zero--;
                    else ones--;
                    i++;
                }
            }
            j++;
        }
        if(zero==0) return res-1;
        return res;
    }
};