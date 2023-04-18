class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
       stack<int> st;
        int ind = 0;
        int n = pushed.size();
        for(int i = 0 ; i < n ; i++) {
            bool ok = false;
            st.push(pushed[i]);
            while(st.size() and st.top() == popped[ind]) {
                st.pop();
                ind++;
                ok = true;
            }
        }
        return st.empty();
    }
};