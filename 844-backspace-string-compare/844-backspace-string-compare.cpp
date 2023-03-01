class Solution {
public:
    bool backspaceCompare(string s, string t) {
       stack<char> s1, s2;
       for(char ch : s)
       {
           if(ch == '#'){
               if(s1.size()) s1.pop();
           }
           else s1.push(ch);
       }
       for(char ch : t)
       {
           if(ch == '#'){
               if(s2.size()) s2.pop();
           }
           else s2.push(ch);
       }
        string a1 = "", a2 = "";
        while(s1.size())
        {
            a1 += s1.top();
            s1.pop();
        }
        while(s2.size())
        {
            a2 += s2.top();
            s2.pop();
        }
        return a1 == a2;
    }
};