class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>cnt;
        for(int i = 0 ; i <nums.size(); i++){
            ++cnt[nums[i]];
        }
        vector<int>ans;
        for(auto it: cnt){
            if(it.second == 1)ans.push_back(it.first);
        }
        return ans;
    }
};