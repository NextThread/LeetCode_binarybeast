class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            //we just need to push positive asteroids to the stack
            if(st.empty() || ast[i]>0)
            st.push(ast[i]);
            
            //in cases a negative asteroid approach 
            else{
                //keep destroying positives untill a positive of higher value is met or the stack becomes empty 
                while(!st.empty() && st.top() > 0 && st.top() < abs(ast[i])){
                    st.pop();
                }
                
                //at this point the negative meets a positive asteroid of same magnitude 
                if(!st.empty() && st.top() == abs(ast[i])){
                    st.pop();
                }
                else{
                    //if the stack becomes/is empty or the top is now negative, we have no choice but to put the current negative in stack too 
                    if(st.empty() || st.top() < 0){
                        st.push(ast[i]);
                    }
                }
            }
        }

        vector<int> ans(st.size(),0);
        int size = st.size();

        while(!st.empty()){
            //insert elements in reverse order 
            ans[--size] = st.top();
            st.pop();
        }

        return ans;
    }
};