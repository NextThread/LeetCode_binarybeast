//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
 int maxIndexDiff(int arr[], int n) {
        int prefixMini[n], suffixMaxi[n], ans = 0, l = 0, r = 0;
        
        prefixMini[0] = arr[0];
        for(int i=1;i<n;i++){
            prefixMini[i] = min(prefixMini[i-1],arr[i]);
        }
        
        suffixMaxi[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMaxi[i] = max(suffixMaxi[i+1],arr[i]);
        }
        
        while(l<n){
            while(r<n && suffixMaxi[r]>=prefixMini[l])r++;
            ans = max(ans,r-l-1);
            l++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends