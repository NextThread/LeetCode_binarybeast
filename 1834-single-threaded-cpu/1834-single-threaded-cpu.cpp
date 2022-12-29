class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        set<pair<int,int>> order;
        vector<int> res;
        int n = tasks.size();
        for(int i = 0 ; i < n ; ++i) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        long long t = 1;
        for(int i = 0 ; i < n || !order.empty() ; ) {
            while(i < n && tasks[i][0] <= t) {
                order.insert({tasks[i][1], tasks[i][2]});
                ++i;
            }
            if(!order.empty()) {
                t += order.begin()->first;
                res.push_back(order.begin()->second);
                order.erase(order.begin());  
            }
            else{
                t = tasks[i][0];
            }
        }
        return res;
    }
};