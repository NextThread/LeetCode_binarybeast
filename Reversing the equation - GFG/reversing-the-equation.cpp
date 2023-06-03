//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
             stack<string> st;
          string ans="";
          for ( int i=0;i<=s.size();i++)
          {
              if( s[i]=='*' || s[i]=='-'|| s[i]== '+'|| s[i]=='/')
              {
                  st.push(ans);
                  ans=s[i];
                  st.push(ans);
                  ans="";
              }
              else {
                  ans=ans+s[i];
              }
          }
              st.push(ans);
               
          
          
          string str="";
          while(!st.empty())
          {
             string d=st.top();
              
              str=str+d;
              st.pop();
          }
          return str;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends