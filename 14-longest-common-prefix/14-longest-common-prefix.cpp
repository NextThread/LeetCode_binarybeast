class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i = 0, j = 0;
        string res = "";
        string s1 = strs[0], s2 = strs[strs.size()-1];
        while(i < s1.length() && j < s2.length())
        {
            if(s1[i] != s2[j]) break;
            res += s1[i];
            i++;
            j++;
        }
        return res;
    }
};