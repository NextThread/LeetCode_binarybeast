class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> pro(n + 1, 0); // for calculating prob
        
        vector<pair<int,double>> adj[n + 1];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        } // make the list first
        
        priority_queue<pair<double,int>> pq;
        pro[start] = 1; // start from 1 as src
        pq.push({1, start});
        while (!pq.empty()) {
            int node = pq.top().second; // node and prob
            double p = pq.top().first;
            pq.pop();
            for (auto it : adj[node]) { // look for max one
                if (pro[it.first] < (it.second * pro[node])) {
                    pro[it.first] = (it.second * pro[node]);
                    pq.push({pro[it.first], it.first});
                }
            }
        }
        return pro[end];
    }
};