class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0) return "";
        stringstream ss(s);
        string word;
        string res="";
        while(ss>>word){
            reverse(word.begin(),word.end());
            res+=word;
            res+=" ";
        }
        res.erase(res.size() - 1);
        return res;
    }
};