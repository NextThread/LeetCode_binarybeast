class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        if(n<1) return ans;

        for(int i = 0; i<n;){
            int low = i, high = i;

            while(high < n-1 && nums[high+1] == nums[high]+1) high++;

            if(high > low) ans.push_back(to_string(nums[low])+"->"+to_string(nums[high])); 
            else ans.push_back(to_string(nums[high])); 

            i = high+1;
        }

        return ans;
    }
};