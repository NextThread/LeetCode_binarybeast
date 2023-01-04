class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int>mp;
        for(int x : tasks) mp[x]++;
        int cnt = 0;
        for(auto it : mp) {
            if (it.second == 1) return -1;
            cnt += (it.second + 2) / 3;
        }
        return cnt;
    }
};