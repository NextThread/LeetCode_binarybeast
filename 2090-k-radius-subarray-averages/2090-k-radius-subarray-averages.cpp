class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;

        if(nums.size()>=2*k+1)
        {
            int i=0,j=2*k+1;
            long long int sum=0;
            // storing sum .
            for(int p=0;p<2*k+1;p++) 
                sum+=nums[p];
            // making first k elements -1.
            for(int i=0;i<k;i++)
                ans.push_back(-1);
            // simple sliding window.
            while(j<nums.size())
            {
                ans.push_back(sum/(2*k+1));
                sum+=nums[j]-nums[i];
                j++;
                i++;
            }

            ans.push_back(sum/(2*k+1));
        }
        //making the rest of the elements -1.
        while(ans.size()<nums.size()) 
            ans.push_back(-1);
        return ans;
    }
};