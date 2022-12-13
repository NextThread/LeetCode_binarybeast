class Solution {
public:
int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if(j<0 || j>=mat[0].size()) return 1e8;
    if(i==0) return mat[0][j];
    if(dp[i][j] != -1) return dp[i][j];

    int u=mat[i][j] + f(i-1, j, mat, dp);
    int ld=mat[i][j] + f(i-1, j-1, mat, dp);
    int rd=mat[i][j] + f(i-1, j+1, mat, dp);

    return dp[i][j] = min(u, min(ld, rd));
}

int minFallingPathSum(vector<vector<int>> &mat)
{
    int m=mat.size(), n=mat[0].size();
    vector<vector<int>> dp(m, vector<int> (n, -1));
    int mini=1e8;
    for(int j=0; j<n; j++)
        mini = min(mini, f(m-1, j, mat, dp));
    return mini;
}
};