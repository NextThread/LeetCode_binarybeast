class Solution {
public:
    
    int dp[100000]; // 
    
    int rec(int i, vector<int>& cost) {
        //1st step: base case
        
        if(i >= cost.size()) return 0;
        
        if(dp[i] != -1) return dp[i]; // 
        
        int op1 = cost[i] + rec(i+1, cost);
        
        int op2 = cost[i] + rec(i+2, cost);
        
        return dp[i] = min(op1, op2); // 
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        memset(dp, -1, sizeof(dp)); // 
        
        int jump_from_first_index = rec(0, cost);
        
        int jump_from_second_index = rec(1, cost);
        
        return min(jump_from_first_index, jump_from_second_index);
    }
};