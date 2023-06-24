class Solution {
public:
    
    int dp[20][100000];
    
	int rec(int i, int diff, vector<int>& rods,int n){
		if(i == n) 
        {
			if(!diff) return 0;
			return -1e9;
		}
		if(dp[i][5999+diff] != -1) return dp[i][5999+diff];
		int op1 = rods[i] + rec(i+1, diff + rods[i], rods, n);
		int op2 = rec(i + 1, diff - rods[i], rods, n);
		int op3 = rec(i + 1, diff, rods, n);
		return dp[i][5999 + diff] = max({op1, op2, op3});
	}

	int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof dp);
		return rec(0, 0, rods, rods.size());
	}
};