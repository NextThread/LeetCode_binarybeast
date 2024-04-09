class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        int sz = size(tickets);
        int cap = tickets[k];  
        for (int i = 0; i < sz; i++)
            res += min(cap - (i > k), tickets[i]);
        return res;
    }
};