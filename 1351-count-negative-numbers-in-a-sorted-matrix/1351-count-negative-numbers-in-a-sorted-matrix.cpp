class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        /*
        
        4   3   2  -1
        3   2   1  -1
        1   1  -1  -2
       -1  -1  -2  -3
        
        
        */
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                cnt += (grid[i][j] < 0);
            }
        }
        return cnt;
    }
};