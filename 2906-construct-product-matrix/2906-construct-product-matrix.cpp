class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    vector<long long> rows, pref_r{1}, suf_r{1};
    for (const auto &r : g)
        rows.push_back(accumulate(begin(r), end(r), 1LL, [](long long res, int v){
            return (res * v) % 12345;
        }));
    for (int i = 0; i < g.size(); ++i) {
        pref_r.push_back(pref_r.back() * rows[i] % 12345);
        suf_r.push_back(suf_r.back() * rows[m - i - 1] % 12345);
    }
    for (int i = 0; i < g.size(); ++i) {
        vector<long long> pref{1}, suf{1};
        for (int j = 0; j < g[i].size(); ++j) {
            pref.push_back(pref.back() * g[i][j] % 12345);
            suf.push_back(suf.back() * g[i][n - j - 1] % 12345);
        }
        for (int j = 0; j < n; ++j)
            g[i][j] = pref_r[i] * suf_r[m - i - 1] * pref[j]* suf[n - j - 1] % 12345;
    }
    return g;
}
};