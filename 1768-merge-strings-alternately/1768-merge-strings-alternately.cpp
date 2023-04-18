class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       string res;
        int i = 0, j = 0;
        while(i < word1.size() or j < word2.size()) {
            if(i < word1.size()) res += word1[i];
            if(j < word2.size()) res += word2[j];
            i++;
            j++;
        }
        return res;
    }
};