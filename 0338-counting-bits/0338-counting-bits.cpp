class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i = 0 ; i <= n ; i++){
            ans.push_back(__builtin_popcount(i)); // __builtin_popcount is a stl function used to count no of setbits in an integer
        }
        return ans;
    }
};