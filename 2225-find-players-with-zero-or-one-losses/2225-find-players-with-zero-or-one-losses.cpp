class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        //   matches[i] = [winner[i], loser[i]]
        map<int, int> lost;
        for (auto it : matches)
        {
            if (lost.find(it[0]) == lost.end()) lost[it[0]] = 0;
            lost[it[1]]++;
        }
        
        vector<int> zero, ones;
        for (auto[a,b] : lost)
        {
            if (b == 0) zero.push_back(a);
            if (b == 1) ones.push_back(a);
        }
        return {zero,ones};
    }
};