class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> mp;
        for (int i = 0; i < t.size(); i++)
        {
            mp[t[i]] = i;
        }
        
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            res += abs(mp[s[i]] - i);
        }
        
        return res;
    }
};