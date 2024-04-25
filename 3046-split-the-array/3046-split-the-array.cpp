class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
         vector<int> freq(101, 0);
    for(auto n: nums) freq[n]++;
    for(auto f: freq) if(f > 2) return false;
    return true;
    }
};