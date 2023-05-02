class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int res = 0, curr = -1;
        for(auto &d: divisors){
            int score = 0;
            for(auto &it: nums)     
                score += (it % d == 0);
            if(score >= curr){
                if(score == curr)       
                    res = min(res, d);
                else                    
                    res = d;                    
                curr = score;
            }
        }
        return res;
    }
};