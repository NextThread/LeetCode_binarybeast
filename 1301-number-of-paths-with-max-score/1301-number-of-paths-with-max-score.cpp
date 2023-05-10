class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int mod = 1000000007, n = board.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1)), cnt(n+1,vector<int>(n+1));
        board[n-1][n-1] = board[0][0] = '0';
        cnt[n-1][n-1] = 1;
        for(int i=n-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                if(board[i][j] != 'X'){
                    int m = max({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
                    dp[i][j] = (board[i][j]-'0')+m;
                    if(dp[i+1][j] == m) cnt[i][j] = (cnt[i][j]+cnt[i+1][j]) % mod;
                    if(dp[i][j+1] == m)  cnt[i][j] = (cnt[i][j]+cnt[i][j+1]) % mod;
                    if(dp[i+1][j+1] == m) cnt[i][j] = (cnt[i][j]+cnt[i+1][j+1]) % mod;
                }
            }
        }
        return {cnt[0][0]?dp[0][0]:0,cnt[0][0]};
    }
};