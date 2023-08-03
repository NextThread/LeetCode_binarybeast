class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        
        if (digits.size() == 0) {
            return answer;
        }
        
        answer.push_back("");

        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (auto number: digits) {
            string &letters = mapping[number - '2'];
            
            // Fix the vector size
            // "a", "b", "c" -> "a", "b", "c", "a", "b", "c", "a", "b", "c"
            int sz = answer.size();
            for (int i = 1; i < letters.size(); ++i) {
                for (int j = 0; j < sz; ++j)
                    answer.push_back(answer[j]);
            }
            
            // Append the current number's letters to all the existing strings
            // "a", "b", "c", "a", "b", "c", "a", "b", "c" ->
            // "ad", "bd", "cd", "ae", "be", "ce", "af", "bf", "cf"
            int pos = 0;
            for (int i = 0; i < letters.size(); ++i)
                for (int j = 0; j < answer.size()/letters.size(); ++j)
                    answer[pos++].push_back(letters[i]);
        }
        return answer;
    }
};