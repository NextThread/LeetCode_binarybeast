//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int f(int n) {
      int cnt = 0;
      while(n) {
          int rsbm = n & -n;
          n -= rsbm;
          cnt++;
      }
      return cnt;
  }
  
    int setBits(int N) {
        return f(N);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends