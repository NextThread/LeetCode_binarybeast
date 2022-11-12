class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     vector<int>dict(256, -1);
      // pwwkew
        int start = -1, maxlen=0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++) {
            start = max(start, dict[s[i]]);
            dict[s[i]] = i;
            maxlen = max(maxlen, i-start);
        }
        return maxlen;
    }
};