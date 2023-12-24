class DSU {
    vector<int> par, rank;
public:
    DSU(int n) : par(n), rank(n) {
        iota(begin(par), end(par), 0);      // initializes each node's parent to be itself - fills as [0,1,2,3,...,n]
    }
    int find(int x) {
        if(x == par[x]) return x;           // x is itself the parent of this component
        return find(par[x]);                // recurse for parent of x
    }
    bool Union(int x, int y) {
        auto xp = find(x), yp = find(y);    // find parents of x and y, i.e, representatives of components that x and y belong to
        if(xp == yp) return false;          // x and y already belong to same component - not possible to union
        return par[xp] = yp;                // union x and y by making parent common
    }
    // iterative implementation of find
    // int find(int x) {  
    //     while(x != par[x]) x = par[x];
    //     return par[x];
    // }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        DSU ds(size(e)+1);
        for(auto& E : e) 
            if(!ds.Union(E[0], E[1])) return E;	// not possible to union - adding this edge was causing the cycle
        return { };    // un-reachable
    }
};