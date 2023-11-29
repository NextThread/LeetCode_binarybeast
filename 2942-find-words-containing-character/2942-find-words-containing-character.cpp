class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ind;
        for(int i = 0 ; i < words.size() ; i++) {
            bool found = false;
            for(char &ch : words[i]) {
                if(ch == x) found = true;
            }
            if(found) ind.push_back(i);
        }
        return ind;
    }
};