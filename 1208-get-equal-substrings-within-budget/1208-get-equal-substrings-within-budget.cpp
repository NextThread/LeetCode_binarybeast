class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0, N = s.size(), cost = 0, ans = 0;
        for (; j < N; ++j) {
            cost += abs(s[j] - t[j]);
            for (; cost > maxCost; ++i) cost -= abs(s[i] - t[i]);
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};