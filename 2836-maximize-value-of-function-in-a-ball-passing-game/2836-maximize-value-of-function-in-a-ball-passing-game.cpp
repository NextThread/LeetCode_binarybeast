class Solution {
public:
    long long getMaxFunctionValue(vector<int>& a, long long k) {
        int m = 40, n = a.size();
        // dp[i][j] means from j, move 2^i steps, (end point, profit)
        vector<vector<pair<int, long long>>> dp(m, vector<pair<int, long long>>(n));
        for (int j = 0; j < n; ++j) dp[0][j] = make_pair(a[j], a[j]);
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = dp[i - 1][j].first;
                dp[i][j] = make_pair(dp[i - 1][x].first, dp[i - 1][j].second + dp[i - 1][x].second);
            }
        }
        function<long long(int, long long)> fuck = [&](int now, long long p) -> long long {
            if (p == -1) return 0;
            if ((k & (1ll << p)) == 0) return fuck(now, p - 1);
            return dp[p][now].second + fuck(dp[p][now].first, p - 1);
        };
        long long res = 0;
        for (int i = 0; i < n; ++i) res = max(fuck(i, m - 1) + i, res);
        return res;
    }
};