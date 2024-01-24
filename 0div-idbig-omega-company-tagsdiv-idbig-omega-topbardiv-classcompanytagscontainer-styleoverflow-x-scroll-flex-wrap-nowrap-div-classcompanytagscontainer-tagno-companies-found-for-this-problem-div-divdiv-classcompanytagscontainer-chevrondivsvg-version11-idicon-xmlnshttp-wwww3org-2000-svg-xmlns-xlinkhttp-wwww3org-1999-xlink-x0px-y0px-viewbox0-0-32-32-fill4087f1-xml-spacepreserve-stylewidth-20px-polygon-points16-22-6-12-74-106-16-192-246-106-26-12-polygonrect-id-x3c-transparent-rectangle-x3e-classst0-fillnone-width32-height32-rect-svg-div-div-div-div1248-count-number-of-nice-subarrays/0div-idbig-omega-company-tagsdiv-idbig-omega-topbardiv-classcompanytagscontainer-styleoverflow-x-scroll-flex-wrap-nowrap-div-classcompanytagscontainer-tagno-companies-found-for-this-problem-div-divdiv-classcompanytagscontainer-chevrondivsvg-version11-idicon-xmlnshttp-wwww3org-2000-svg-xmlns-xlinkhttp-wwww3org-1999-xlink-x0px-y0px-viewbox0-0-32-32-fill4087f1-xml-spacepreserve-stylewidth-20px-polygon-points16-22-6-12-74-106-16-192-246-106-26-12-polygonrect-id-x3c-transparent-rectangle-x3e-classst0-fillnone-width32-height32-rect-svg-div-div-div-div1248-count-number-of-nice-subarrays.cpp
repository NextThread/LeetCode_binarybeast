class Solution {
public:
    int numarr(vector<int>& nums, int k) {
        int ans=0;
        int count=0;
        int i=0,j=0,n=nums.size();
        while(j<n){
            if(nums[j]%2==1){
                count++;
            }
            if(count>k){
                while(i<=j && count>k){
                    if(nums[i]%2==1){
                        count--;
                    }
                    i++;
                }
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numarr(nums,k)-numarr(nums,k-1);
    }
};