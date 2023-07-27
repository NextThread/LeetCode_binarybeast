class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        priority_queue<int> pq(batteries.begin(), batteries.end());
        long long res = 0;
        long long sum = accumulate(batteries.begin(), batteries.end(), 0ll);
        while(pq.top() > sum / n) {
            sum -= pq.top();
            pq.pop();
            --n;
        }
        return sum/n;
    }
};