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
    
    map<char, int> mp;
    
    for(int i = 0 ; i < s.size() ; i++) {
        
        mp[s[i]]++;
        
        if(mp[s[i]] == 2) { // repeating
            res += s[i];
            return res;
        }
        
    }
    // cout << res << ' ';
    return "-1";
}
