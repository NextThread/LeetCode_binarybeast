class Solution {
public:
    double t[101][101]; // declaring 2 d array, to store some already computed results
    double solve(int poured, int row, int glass)
    {
        // if any of the condition fails
        if(row < 0 || glass > row || glass < 0)
        {
            return 0.00;
        }
        
        // if we reach at our target 
        if(row == 0 && glass == 0)
        {
            return poured;
        }
        
        // if result is already computed, then return from here
        // this one line which we say to add
        if(t[row][glass] > -1)
        {
            return t[row][glass];
        }
        
        // how much comes from left part- first coordinate(i -1, j - 1) then keep 1 for themself and then divide by 2
        double left = (solve(poured, row - 1, glass - 1) - 1) / 2;
        
        // if comes negative then, in reality zero comes
        if(left < 0)
        {
            left = 0;
        }
        
        // how much comes from right part- first coordinate(i - 1, j) then keep 1 for themself and then divide by 2
        double right = (solve(poured, row - 1, glass) - 1) / 2;
        
        // if comes negative then, in reality zero comes
        if(right < 0)
        {
            right = 0;
        }
        
        // and add coming from left and right
        double total = left + right;
        
        return t[row][glass] = total;// and finally return total
        
        
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(t, -1, sizeof(t));
        
        // solve funcion which return answer
        return min(1.00, solve(poured, query_row, query_glass));
    }
};