class Solution {
public:
    int minimumLength(string s) {
          int l = 0, r = s.size()-1;
        while (l < r && s[l] == s[r])
        {
            char ch = s[l];
            while (l <= r && s[l] == ch) ++l;
            while (r >= l && s[r] == ch) --r;
        }
        return r-l+1;
    }
};