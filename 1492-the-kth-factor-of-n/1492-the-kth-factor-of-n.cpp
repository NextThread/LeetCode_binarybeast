class Solution {
public:
    int kthFactor(int n, int k) {
        int fact = 1;
        vector<int> facts;
        for(int i = 1 ; i <= n ; i++) {
            if(n % i == 0) facts.push_back(i);
        }
        if(facts.size() < k) return -1;
        return facts[k-1];
    }
};