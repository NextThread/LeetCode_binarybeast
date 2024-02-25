struct UnionFind {
    std::vector<int> fa;
    std::vector<int> size;
    UnionFind(int n) : fa(n), size(n, 1) {
        for (int i = 0; i < n; ++i) fa[i] = i;
    }
    int getFa(int i) {
        return i == fa[i] ? i : (fa[i] = getFa(fa[i]));
    }
    void merge(int i, int j) {
        int fi = getFa(i), fj = getFa(j);
        if (fi == fj) return;
        if (size[fi] > size[fj]) swap<int>(fi, fj);
        size[fj] += size[fi];
        fa[fi] = fj;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& a) {
        int n = a.size(), m = *max_element(a.begin(), a.end());
        vector<int> fst(m+1, -1);
        UnionFind u(n);
        for (int i = 0; i < n; ++i) {
            for (int p = 2; p * p <= a[i]; ++p) {
                if (a[i] % p != 0) continue;
                if (fst[p] != -1) u.merge(fst[p], i);
                else fst[p] = i;
                while (a[i] % p == 0) a[i] /= p;
            }
            if (a[i] > 1) {
                if (fst[a[i]] != -1) u.merge(fst[a[i]], i);
                else fst[a[i]] = i;
            }
        }
        return u.size[u.getFa(0)] == n;
    }
};