//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		       map<char,int> mp;

    int i=0,j=0,freq=0,ans=0;

    while(j<s.size())

    {

        mp[s[j]]++;

        freq=max(freq,mp[s[j]]);

        while(j-i+1-freq>k)

        {

           // reducing the size of window  from left

            mp[s[i]]--;

            i++;

        }

        //got an answer

        ans=max(ans,j-i+1);

        //again slide the window for final required ans.

        j++;

    }

    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends