//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
     d=d%16;
            int num1=n<<d;
            num1=(num1/(pow(2,16)));
            unsigned int num2=n<<(16-d);
            num2=(num2/(pow(2,16)));
            return {(n<<d)%(65536)+num1,(n<<(16-d))%(65536)+num2};        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends