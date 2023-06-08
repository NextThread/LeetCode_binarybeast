class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        int i = m-1, j = 0;
		
        int cnt = 0;
        
        // start from last row, and keep on going upward, as lower the row, now of neg is much more
        
        while(i >= 0 and i < m and j >= 0 and j < n)
        {
            if(grid[i][j] < 0){
                cnt += (n-j); // when the first occurrence of a number in a row is -ve, all following numbers will be -ve. So, add their count.
                i = i-1; // then move to the above row
            }
            else{
                j = j+1; //else move to the right (i.e. to the next column)
            }
                
        }              
        return cnt;
    }
};