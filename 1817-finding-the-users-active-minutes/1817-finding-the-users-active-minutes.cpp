class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans (k, 0);
        map<int, set<int>> usermap;
        for (auto i: logs) {
            usermap[i[0]].insert(i[1]);
        }
        for (auto i: usermap) {
            ans[i.second.size() - 1] ++;
        }
        return ans;
    }
};