class Solution {
    int dp[501][501];
private:
    int memo(vector<int>&cost, vector<int> &time, int index, int walls) {
        if(walls <= 0) return 0;//can be one of the possible way
        if(index >= cost.size()) return 1e9;//Neglect this by returning unusually large value
        if(dp[index][walls] != -1) return dp[index][walls];
        int notTake = 0 + memo(cost, time, index + 1, walls);
        int take = cost[index] + memo(cost, time, index + 1, walls - time[index] - 1);
        return dp[index][walls] = min(notTake, take);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp, -1, sizeof dp);
        return memo(cost, time, 0, n);
    }
};
