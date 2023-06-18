//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    string res = "";
    set<char> st;
    for(int i = 0 ; i < s.size() ; i++) {
        if(st.find(s[i]) != st.end()) { // present already in our set
            res += s[i];
            return res;
        }
        st.insert(s[i]);
    }
    
    return "-1";
}
