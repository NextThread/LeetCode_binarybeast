//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
  int evenIndex=0,oddIndex=0;

     

     for(int i=0;i<s.size();i++)

     {

         if(s[i]=='1')

         {

             if(i&1) oddIndex++;   //1 at odd position

             else    evenIndex++;  //1 at even position

         }

     }

     

     //if difference of even and odd on modulo opearation by 3 gives 0 then div by 3

     

     if(abs(evenIndex-oddIndex)%3 == 0)

       return 1;

     else

       return 0;	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends