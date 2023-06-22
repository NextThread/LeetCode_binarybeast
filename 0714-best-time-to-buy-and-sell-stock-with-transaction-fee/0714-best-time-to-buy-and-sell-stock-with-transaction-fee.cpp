class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s0 = 0, s1 = INT_MIN; 
        for(int p:prices) {
            int tmp = s0;
            s0 = max(s0, s1+p);
            s1 = max(s1, tmp-p-fee);
        }
        return s0;
    }
};