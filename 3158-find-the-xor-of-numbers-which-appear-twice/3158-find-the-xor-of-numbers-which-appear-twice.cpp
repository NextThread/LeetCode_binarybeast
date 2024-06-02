class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((nums[i]^nums[j])==0)
                {
                    ans.push_back(nums[i]);
                }
            }
        }
        int k = ans.size();
        int ansxor = 0;
        for(int i=0;i<k;i++)
        {
           ansxor = ansxor^ans[i];
        }
        return ansxor;
    }
};