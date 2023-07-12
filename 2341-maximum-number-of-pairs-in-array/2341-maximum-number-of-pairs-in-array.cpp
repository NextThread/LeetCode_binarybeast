class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int cnt = 0;
        vector<int> vis(nums.size(), false);
        for(int i = 0 ; i < nums.size() ; i++)
        {
            for(int j = i+1; j < nums.size() ; j++)
            {
                if(nums[i] == nums[j] and vis[i] == false and vis[j] == false)
                {
                    cnt++;
                    vis[i] = true;
                    vis[j] = true;
                }
            }
        }
        return {cnt, (int)nums.size()-cnt*2};
    }
};