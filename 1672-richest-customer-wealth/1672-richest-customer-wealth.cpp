class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       int maxx =  INT_MIN;
        for(int i = 0 ; i < accounts.size(); i++)maxx = max(maxx, accumulate(accounts[i].begin(), accounts[i].end(), 0));
        return maxx;
    }
};