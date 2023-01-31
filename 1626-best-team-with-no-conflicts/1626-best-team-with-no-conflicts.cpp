class Solution {
public:
     int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        int n = scores.size();
        for (int i=0; i<n; i++) players.push_back({ages[i], scores[i]});
        sort(players.rbegin(), players.rend());
        int ans = 0;
        vector<int> dp(n);
        for (int i=0; i<n; i++) {
            int score = players[i].second;
            dp[i] = score;
            for (int j=0; j<i; j++)
                if (players[j].second >= players[i].second) dp[i] = max(dp[i], dp[j] + score);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};