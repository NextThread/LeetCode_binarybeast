// class Solution {
// public:
//     int dfs(vector<int>& dp,vector<int>& nums , int coins , int i , int n){
//         if(coins <= 0){
//             return 0;
//         }
//         if(i == n-1){
//             if(nums[i] <= coins){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }
//         if(dp[i] != -1){
//             return dp[i];
//         }
//         int can = 0 , cant = 0;
//         if(nums[i] <= coins){
//             can = 1 + dfs(dp , nums , coins - nums[i] , i + 1 , n);
//         }
//         cant = dfs(dp , nums , coins , i + 1 , n);
//         return dp[i] = max(can , cant);
//     }
//     int maxIceCream(vector<int>& costs, int coins) {
//         int n = costs.size();
//         vector<int> dp(n+1 , -1);
//         sort(costs.begin() , costs.end());
//         return dfs(dp , costs , coins , 0 , n);
//     }
// };


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        for(int i = 0 ; i < costs.size() ; i++)
        {
            if(coins >= costs[i]) coins -= costs[i];
            else return i;
        }
        return costs.size();
    }
};
