//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
 unordered_map<char,int>mp;
    int i=0;
    int j=0;
    int length =-1;
    while(j<s.size()){
        mp[s[j]]++;
        if(mp.size()==k){
            length = max(length,j-i+1);
        }
        while(mp.size()>k){
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(s[i]);
            i++;
            
        }
        j++;
        
        }
        return length;    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends