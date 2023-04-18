class Solution {
public:
    string simplifyPath(string path) {
      stack<string> st;
        string res = "";
        for(int i = 0;  i < path.length() ; i++)
        {
            if(path[i] == '/') continue; // skip it
            string temp;
			// iterate till we doesn't traverse the whole string and doesn't encounter the last
            while(i < path.size() && path[i] != '/')
            {
                temp += path[i]; // add the current path
                i++;
            }
            if(temp == ".") continue; // skip again
            else if(temp == "..") {
                if(!st.empty())
                    st.pop();
            }
            else
			// push the directory file name to stack
                st.push(temp);
        }

        while(!st.empty()) {
            res = "/" + st.top() + res; // adding this way, helps us, that we don't need to reverse the string after that
            st.pop();
        }
        
        if(res.size() == 0)  return "/"; // if no directory is there 
        return res;
    }
};