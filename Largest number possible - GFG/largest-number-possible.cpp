//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
  if (N*9 < S or (S == 0 and N > 1)) return "-1";
        string s;
        while (N and S) {
            s += S >= 9 ? '9' : (S+'0');
            S -= S >= 9 ? 9 : S;
            N--;
        }
        while (N--) s += '0';
        return s;    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends