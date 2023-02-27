class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>>res;
    if(nums.size() < 3) return res;
    set<vector<int>> st;
    for(int i = 0 ; i < nums.size()-1 ; i++)
    {
        int lo = i+1;
        int hi = nums.size()-1;
        while(lo < hi)
        {
            if(nums[i]+nums[lo]+nums[hi] == 0)
            {
                st.insert({nums[i], nums[lo], nums[hi]});
                lo++,hi--;
            }
            else if(nums[i]+nums[lo]+nums[hi] < 0) lo++;
            else hi--;
        }
    }
    for(auto it : st) res.push_back(it);
    return res;
    }
};