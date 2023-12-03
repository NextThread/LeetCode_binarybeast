class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        return inner_product(begin(p)+1, end(p), begin(p), 0, [](int s, int x){return s+x;}, [](auto& x, auto& y){return max(abs(x[0]-y[0]),abs(x[1]-y[1]));});
    }
};