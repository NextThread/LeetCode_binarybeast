class Solution {
public:
    string reverseVowels(string s) {
        int lo = 0, hi = s.length() - 1;
        while (lo < hi) {
            lo = s.find_first_of("aeiouAEIOU", lo);
            hi = s.find_last_of("aeiouAEIOU", hi);
            if (lo < hi) swap(s[lo++], s[hi--]);
        }
        return s;
    }
};