class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, 0), upper(26, 0);
        for (auto x: word)
        {
            if (islower(x))
                lower[x - 'a']++;
            else
                upper[x - 'A']++;
        }

        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (lower[i] != 0 && upper[i] != 0)
            {
                res++;
            }
        }

        return res;
    }
};