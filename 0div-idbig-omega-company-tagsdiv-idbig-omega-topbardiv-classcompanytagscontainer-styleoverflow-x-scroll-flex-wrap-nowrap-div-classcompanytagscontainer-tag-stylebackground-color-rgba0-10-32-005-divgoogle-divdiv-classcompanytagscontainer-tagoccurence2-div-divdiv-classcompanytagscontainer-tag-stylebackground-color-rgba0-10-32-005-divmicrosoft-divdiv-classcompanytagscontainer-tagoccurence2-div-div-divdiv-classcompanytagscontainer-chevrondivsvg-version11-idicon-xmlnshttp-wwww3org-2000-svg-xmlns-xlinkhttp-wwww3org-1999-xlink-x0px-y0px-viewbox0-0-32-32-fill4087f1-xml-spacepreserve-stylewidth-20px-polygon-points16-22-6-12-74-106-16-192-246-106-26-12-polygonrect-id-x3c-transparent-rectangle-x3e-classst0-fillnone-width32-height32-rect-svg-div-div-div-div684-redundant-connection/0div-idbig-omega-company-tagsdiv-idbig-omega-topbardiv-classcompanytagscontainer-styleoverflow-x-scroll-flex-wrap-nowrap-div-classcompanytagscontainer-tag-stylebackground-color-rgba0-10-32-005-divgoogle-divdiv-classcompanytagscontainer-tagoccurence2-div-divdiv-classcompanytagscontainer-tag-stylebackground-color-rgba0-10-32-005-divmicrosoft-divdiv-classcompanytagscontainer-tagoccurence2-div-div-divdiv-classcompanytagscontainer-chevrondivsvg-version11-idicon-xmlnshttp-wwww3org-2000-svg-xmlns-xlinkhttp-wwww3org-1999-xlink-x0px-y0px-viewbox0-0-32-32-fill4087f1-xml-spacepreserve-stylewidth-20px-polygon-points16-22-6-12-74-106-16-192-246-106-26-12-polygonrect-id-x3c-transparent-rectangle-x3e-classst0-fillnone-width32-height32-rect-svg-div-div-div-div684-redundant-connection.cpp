class DSU{
    vector<int> par, rank;
    public:
    DSU(int n): par(n), rank(n) {
        iota(begin(par), end(par), 0);
    }
    
    int find(int x) {
        if(x == par[x]) return x;
        return find(par[x]);
    }
    
    bool Union(int x, int v) {
        auto xp = find(x);
        auto vp = find(v);
        if(xp == vp) return false;
        return par[xp] = vp;
    }
};

class Solution {
public:  
    // union find o(n*n)
    // path compression o(log(n))
    // union by rank o(n)
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU ds(size(edges)+1);
        
        for(auto it : edges) {
            if(!ds.Union(it[0], it[1])) return it;
        }
        return {};
    }
};