//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isPossible(int x,int base,int m){
        return ceil(log2(x)/log2(base))==m;
    }
    
    string baseEquiv(int n, int m){
        for(int i=2;i<=32;i++){
            if(isPossible(n,i,m))
                return "Yes";
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends