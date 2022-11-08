class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (int i = 0 ; i < s.size() ; i++){
            st.push(s[i]); // keep pushing into the stack
            while (!st.empty() && ((st.top() == s[i+1]+32) || (st.top() == s[i+1]-32))){  // if aA or Aa
                st.pop(); // keep popping
                i++; // increrment 
            }
        }
		    string ret = "";
        while(!st.empty()) {
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};