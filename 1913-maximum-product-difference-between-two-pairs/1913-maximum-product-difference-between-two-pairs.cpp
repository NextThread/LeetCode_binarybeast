class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
           int max1=0,max2=0,min1=INT_MAX,min2=INT_MAX;
		for(int i=0;i<nums.size();i++) {
            if (nums[i]>max1||nums[i]>max2) {
                max2=max(max1,max2);
                max1=nums[i];
            }
            if (nums[i]<min1||nums[i]<min2) {
                min2=min(min1,min2);
                min1=nums[i];
            }
        }
        return (max1*max2)-(min1*min2);
    }
};