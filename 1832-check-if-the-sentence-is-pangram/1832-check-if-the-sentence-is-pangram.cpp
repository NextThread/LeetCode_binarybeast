class Solution {
public:
    bool checkIfPangram(string s) {
        set<char> st;
        for(char &ch : s) st.insert(ch);
        return st.size() == 26;
    }
};