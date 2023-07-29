class Solution {
public:
    double help(int a,int b,vector<vector<double>>&dp){
        if(a<=0 && b<=0)return 0.5;
        if(a<=0) return 1.0;
        if(b<=0) return 0.0;
        if(dp[a][b]>-1)return dp[a][b];
        vector<pair<int,int>>x = {{100,0}, {75,25} , {50,50}, {25,75}};
        double ans = 0.0;
        for(int i=0;i<4;i++){
            ans += 0.25 * help(a-x[i].first,b-x[i].second,dp);
        }
        return dp[a][b] = ans;
    }
    double soupServings(int n) {
      if(n>5000)return 1.0; // Observation (try to run test cases greater than 5000)
      vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
      return help(n,n,dp);  
    }
};