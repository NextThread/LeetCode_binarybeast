//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    { int count=0, count1=0,ans=INT_MIN;
        // first count all ones in array and convert 1 to -1 ans 0 to 1
        for(int i=0;i<n;i++){
            if(a[i]==1){
                count1++;
                a[i]=-1;
            }else{
                a[i]=1;
            }
        }
       // here we find maximum subarray
        for(int i=0;i<n;i++){
            count=count+a[i];
            if(ans<count){
                ans=count;
            }
            if(count<0){
                count=0;
            }
        }
        // if subarray is negative that is all array contain 1 then we only return count1
        if(ans< 0) return count1;

        return ans+count1; // Your code goes here
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends