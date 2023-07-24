class Solution {
public:
   int minCostConnectPoints(vector<vector<int>>& ps) {
    int n = ps.size(), res = 0, i = 0, connected = 0;
    vector<int> min_d(n, 10000000);
    while (++connected < n) { // jab tak sbhi points connect nhi ho jaate tab tak kaam karo
        min_d[i] = INT_MAX; // kyuki min distance set krna hai, to max se initialize karo
        int curr = i; // current node'
        for (int j = 0; j < n; j++) // uske every neighbourse k distance calculate karo, and minimum ko lo
            if (min_d[j] != INT_MAX) 
            {
                min_d[j] = min(min_d[j], abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]));
                curr = min_d[j] < min_d[curr] ? j : curr;
            }
        res += min_d[curr]; // res k saath wahi minimum distance add karo
        i = curr; // i ko abhi k current node pe set krdo
    }
    return res;
}
};