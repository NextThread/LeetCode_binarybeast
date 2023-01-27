class Solution {
public:
     bool concatenatePossible(string word, unordered_set<string>& dict, unordered_map<string, bool> &memo){
        if(memo.find(word)!= memo.end()){
            return memo[word];
        }
        for(int i=1; i<word.size(); ++i){
            string substring = word.substr(0, i);
            if(dict.count(substring)){
                string restSubstring = word.substr(i);
                if(dict.count(restSubstring) || concatenatePossible(restSubstring, dict, memo)){
                    memo.insert({word, true});
                    return true;
                }
            }
        }
       memo.insert({word, false});
       return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> dict(words.begin(), words.end());
        unordered_map<string, bool> memo;
        for(auto word : words){
            if(concatenatePossible(word, dict, memo)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};