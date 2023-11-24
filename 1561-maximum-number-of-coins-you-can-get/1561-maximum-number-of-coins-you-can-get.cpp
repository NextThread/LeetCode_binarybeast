class Solution {
public:
    int maxCoins(vector<int>& p) {
        int res = 0;
         sort(begin(p), end(p));
    for (int j = p.size() / 3; j < p.size(); j += 2)
        res += p[j];
    return res;
    }
};