//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


    int findFloor(int arr[], int n, int x)
    
    {
      int low=0;
      int high=n-1;
      int ans=-1;
      while(low<=high){
          int mid=(low+high)/2;
          if(arr[mid]>x){
              
              high=mid-1;
          }
          else{
              ans=arr[mid];
              low=mid+1;
          }
      }
      return ans;
        
    }
     int findCeil(int arr[], int n, int x)
    
    {
      int low=0,high=n-1;
      int ans=-1;
      while(low<=high){
          int mid=(low+high)/2;
          if(arr[mid]>=x){
              ans=arr[mid];
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      return ans;
        
    }
    

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr, arr+n);
    return {findFloor(arr, n, x), findCeil(arr, n, x)};
}