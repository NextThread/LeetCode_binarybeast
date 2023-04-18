class Solution {
public:
      void dfs(int n, string s, vector<string> &res)
      {
        if(s.size() > n) return;
        if(s.size() == n){
            res.push_back(s);
            return;
        }
        dfs(n, s + '0', res);
        dfs(n, s + '1', res);
      }
    
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> res;
        string temp = "";
        dfs(nums.size(), temp, res);
        vector<string> all_missing;
        map<string, int> mp;
        for(auto it : nums) mp[it] = 1;
        for(auto it : res) {
            if(find(nums.begin(), nums.end(), it) == nums.end()) {
                return it;
            }
        }
        return "";
        }
};