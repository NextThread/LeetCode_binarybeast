class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = -1, buy = INT_MAX;
        for(int i = 0 ; i < prices.size() ; i++)
        {
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i]-buy);
        }
        return profit;
    }
};