class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 and n == 1) return 1;
        vector<int> in(n+1, 0), out(n+1, 0);
        for(int i = 0 ; i < trust.size() ; i++)
        {
            in[trust[i][0]]++;
            out[trust[i][1]]++;
        }
        for(int i = 0 ; i <= n ; i++)
        {
            if(in[i] == 0 and out[i] == n-1) return i;
        }
        return -1;
    }
};