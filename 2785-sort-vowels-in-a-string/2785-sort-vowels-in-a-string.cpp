class Solution {
public:
    bool isv(char ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or
            ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U';
    }
    string sortVowels(string s) {
        string vowels = "";
        for(char ch : s) {
            if(isv(ch)) vowels += ch;
        }
        sort(vowels.begin(), vowels.end());
        int j = 0;
        int ind = 0;
        while(j < s.size()) {
            if(isv(s[j])) {
                s[j] = vowels[ind];
                ind++;
            }
            j++;
        }
        return s;
    }
};