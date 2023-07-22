class Solution {
public:
    
double dp[26][26][101];
    double rec(int n, int k, int row, int col) {
        if(row<0||row>=n||col<0||col>=n) return 0; 
        if(k==0) return 1; 
        
        if(dp[row][col][k]) return dp[row][col][k]; 
        

        double res =0;
        res =
        rec(n,k-1,row-1,col-2)+
        rec(n,k-1,row+1,col-2)+
        rec(n,k-1,row-2,col-1)+
        rec(n,k-1,row+2,col-1)+
        rec(n,k-1,row-2,col+1)+
        rec(n,k-1,row+2,col+1)+
        rec(n,k-1,row-1,col+2)+
        rec(n,k-1,row+1,col+2);
        
        res/=8;
        return dp[row][col][k]=res;
    }

    
    double knightProbability(int n, int k, int row, int column) {
      memset(dp, 0.0, sizeof dp);
      return  rec(n,k,row,column);
    }
};