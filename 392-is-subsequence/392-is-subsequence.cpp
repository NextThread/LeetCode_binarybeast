class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0;
        int i = 0, j = 0;
        while(i < s.length() && j < t.length())
        {
            if(s[i] == t[j]) {
                cnt++;
                i++;
                j++;
            }
            else j++;
        }
        return cnt == s.length();
    }
};