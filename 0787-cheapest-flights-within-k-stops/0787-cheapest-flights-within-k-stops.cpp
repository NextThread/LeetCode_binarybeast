class Solution {
public:
    int dp[10001][101];
	
    int dfs(vector<vector<pair<int, int>>>& graph, int src, int dst, int k) {
        if (src == dst) return 0; // if reached destination
        if (k <= -1) return INT_MAX; // stops unavailable
        if (dp[src][k] != -1) return dp[src][k]; // check if previously stored
        int ans = INT_MAX;
        for (auto child : graph[src]) {
            int res = dfs(graph, child.first, dst, k-1);
            if (res != INT_MAX)
                ans = min(ans, child.second +res);
        }
        return dp[src][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        memset(dp, -1, sizeof dp);
        vector<vector<pair<int, int>>> graph(n);
        for (auto vec : flights) {
            graph[vec[0]].emplace_back(make_pair(vec[1], vec[2]));
        }
        int ans = dfs(graph, src, dst, K);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};