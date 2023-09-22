//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> bs(int l, int h, int n, int arr[], int x){
        if(l>h || (l == h && arr[l] != x)) return {INT_MAX, INT_MIN};
        if(l == h && arr[l] == x) return {l,l};
        int mid = (h-l)/2 + l;
        vector<int> ls = bs(l, mid - 1, n, arr, x);
        vector<int> rs = bs(mid + 1, h, n, arr, x);
        vector<int> ans;
        if(arr[mid] == x){
            ans = {min(ls[0], mid), max(mid, rs[1])};
        }
        else{
            ans = {min(ls[0], rs[0]), max(rs[1], ls[1])};
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
       vector<int> ans =  bs(0,n-1, n, arr, x);
       vector<int> temp = {-1,-1};
       return ans[0] == INT_MAX ? temp : ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends