class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max_count = 0, count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i >= k and vowels.count(s[i-k])) count--;
            if (vowels.count(s[i])) count++;
            max_count = max(max_count, count);
        }
        return max_count;
    }
};