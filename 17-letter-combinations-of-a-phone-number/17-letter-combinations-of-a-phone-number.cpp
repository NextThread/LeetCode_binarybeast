class Solution {
public:
    unordered_map<char, string> kepypad{{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};  // digits corresponding to the letters
    
    void dfs(int pos, int &len, string str, vector<string> &ans, string &D) {
        if (pos == len) 
        {
            ans.push_back(str); // if we reached the end of the string
        }
        else 
        {
            string letters = kepypad[D[pos]]; // mapping to the letter at the corresponding location to the current digit
            for (int i = 0 ; i < letters.size() ; i++)
            {
                dfs(pos+1, len, str+letters[i], ans, D);
            }
        }
    }
    vector<string> letterCombinations(string D) {
        int len = D.size();
        vector<string> res;
        if (!len) return res;
        dfs(0, len, "", res, D);
        return res;
    }
};