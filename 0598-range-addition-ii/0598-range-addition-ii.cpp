class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& op) {
        int res_m = m, res_n = n;
        
        for (auto op : op) {
            res_m = min(res_m, op[0]); 
            res_n = min(res_n, op[1]);
        }
            
        return res_m * res_n;
    }
};