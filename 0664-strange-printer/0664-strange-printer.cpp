class Solution {
public:
    int f[101][101];
    int dfs(const string& s, int l, int r)
    {
        if (l > r) return 0;
        if (f[l][r] != -1) return f[l][r];
        f[l][r] = dfs(s, l, r - 1) + 1;
        for (int i = l; i < r; ++i)
        {
            if (s[i] == s[r])
            {
                f[l][r] = min(f[l][r], dfs(s, l, i) + dfs(s, i + 1, r - 1));
            }
        }
        return f[l][r];
    }

    int strangePrinter(string s)
    {
        memset(f, -1, sizeof(f));
        int len = s.size();
        return dfs(s, 0, len - 1);
    }
};