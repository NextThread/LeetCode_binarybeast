class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        string res = s1.substr(0, __gcd(size(s1), size(s2)));
        if(s1 + s2 == s2 + s1) return res;
        return "";
    }
};