class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string store = "";
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(s[i] == ' ')
            {
                reverse(store.begin(), store.end());
                res += store;
                res += ' ';
                store = "";
            }
            else{
                store += s[i];
            }
        }
        if(store.length() > 0)
            {
                reverse(store.begin(), store.end());
                res += store;
            }
        return res;
    }
};