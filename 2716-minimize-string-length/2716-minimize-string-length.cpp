class Solution {
public:
    int minimizedStringLength(string s) {
        return set(s.begin(), s.end()).size();
    }
};