class Solution {
public:
    char lower(vector<int> &freq){
        for(int i = 0 ; i < 26 ; i++)
        {
            if(freq[i] != 0) return 'a'+i;
        }
        return 'a';
    }
    string robotWithString(string s) {
        vector<int> freq(26);
        for(char a : s) {
            freq[a-'a']++;
        }
        
        string ans="";
        stack<char> st;
        
        for(char a : s) {
            st.push(a);
            freq[a-'a']--;
            while(st.size() && st.top() <= lower(freq)) {
                auto x = st.top();
                ans += x;
                st.pop();
            }
        }
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};