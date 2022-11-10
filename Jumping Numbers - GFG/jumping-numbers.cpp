//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
        // code here
        // 1000   5-6   if good 
         long long ans=0;

    

    void fun(long long cur,long long target)

    {  

        if(cur>target)

        {   

            return;

        }

        ans=max(ans,cur);

        

        if(cur%10==0)

        {  

            fun(cur*10+1,target);

        }else if(cur%10==9)

        {  

            fun(cur*10+8,target);

        }

        else

        {  

            fun(cur*10+(cur%10+1),target);

            fun(cur*10+(cur%10-1),target);

        }

    }

    long long jumpingNums(long long X) {

        

        for(int i=1;i<=9;i++)

        {  

            if(X>i)

            {  

                fun(i,X);

            }

        }

        

        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends