class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>b;
        string temp = "";
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(s[i] == ' ') {
                b.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        b.push_back(temp);
        int time = 100;
        while(time--)
        {
            map<char, int>mp1;
            map<string, int>mp2;
            for(char ch : pattern) mp1[ch]++;
            string n, m;
            for(string st : b) mp2[st]++;
            for(auto it : pattern) n += mp1[it];
            for(auto it : b) m += mp2[it];
            if(n != m) return false;
            n = "";
            m = "";
        }
        string last1, last2;
        for(int i = 1 ; i < pattern.size() ; i++) 
        {
            if(pattern[i] == pattern[i-1]) last1 += '1';
            else last1 += '0';
        }
        for(int i = 1 ; i < b.size() ; i++) 
        {
            if(b[i] == b[i-1]) last2 += '1';
            else last2 += '0';
        }
        if(last1 != last2) return false;
        return true;
    }
};