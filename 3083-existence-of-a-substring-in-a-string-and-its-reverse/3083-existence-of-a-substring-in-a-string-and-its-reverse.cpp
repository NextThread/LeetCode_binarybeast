class Solution {
public:
    bool isSubstringPresent(string s) {
         bitset<1024> seen;
        for (int i = 0; i < ssize(s) - 1; ++i) {
            const char l = s[i] & 0x1f;
            const char r = s[i + 1] & 0x1f;
            seen[l << 5 | r] = true;
            if (seen[l | r << 5]) return true;
        }
        return false;     
    }
};