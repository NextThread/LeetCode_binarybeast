#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    int dp[102][102];
    long long solve(int nn, int cur_goal,int n,int goal,int k){
          if(cur_goal == goal) return nn == n;
          if(dp[nn][cur_goal] != -1) return dp[nn][cur_goal];
         ll ans = (solve(nn, cur_goal + 1, n, goal, k) * max(0, nn - k)) % mod;  
          ans = ((ans % mod) + (solve(nn + 1, cur_goal + 1, n, goal, k) * (n - nn)) % mod) % mod;
          return dp[nn][cur_goal] = ans;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
           memset(dp, -1, sizeof(dp));
           return solve(0,0,n, goal, k);
    }
};