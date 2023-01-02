class Solution {
public:
    bool detectCapitalUse(string word) {
        int all_upper = 0, all_lower = 0;
        bool first_upper = false;
        for(char ch : word)
        {
            if(isupper(ch)) all_upper++;
            if(islower(ch)) all_lower++;
        }
        if(all_upper == word.length() || all_lower == word.length()) return true;
        if(isupper(word[0])) first_upper = true;
        if(all_upper == 1 && all_lower == word.length()-1 && first_upper) return true;
        return false;
    }
};