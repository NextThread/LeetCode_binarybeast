//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
  int minDiff = INT_MAX;
        
        int a,b;
        
        
        // Approach using N * logM
        
        for(int i=0 ; i<n ; i++){
            
            int target = x - arr[i];
            
            // Now find for the lower bound of the target value
            
            int indx = lower_bound(brr , brr+m , target) - brr;
            
            if(indx < m and minDiff > abs(x - arr[i] - brr[indx])){
                a = arr[i];
                b = brr[indx];
                
                minDiff = abs(x - arr[i] - brr[indx]);
            }
            
            if(indx - 1 >= 0 and minDiff > abs(x - arr[i] - brr[indx-1])){
                a = arr[i];
                b = brr[indx-1];
                
                minDiff = abs(x - arr[i] - brr[indx-1]);
            }
            
            
        }
        
        return {a,b};
    }
        };

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends