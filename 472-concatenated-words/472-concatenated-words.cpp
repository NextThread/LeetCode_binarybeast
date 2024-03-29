class Solution {
public:
     bool check(string word, unordered_set<string>& dict, unordered_map<string, bool> &ump){
        if(ump.find(word) !=  ump.end()) return ump[word];
        for(int i = 1 ; i < word.size() ; ++i) {
            string substring = word.substr(0, i); // check for every substring
            if(dict.count(substring)) { // if substring is pre-stored
                string nextpart = word.substr(i); // the rest substring
                if(dict.count(nextpart) || check(nextpart, dict, ump)) // check if the next substring is been there in our map already or using the next part we can do the same operation(recursive call) and is possible
                {
                    ump.insert({word, true});
                    return true;
                }
            }
        }
       ump.insert({word, false});
       return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end()); // let's remove duplicate words first
        unordered_map<string, bool> mp;
        for(string word : words)
            if(check(word, dict, mp)) res.push_back(word);
        return res;
    }
};