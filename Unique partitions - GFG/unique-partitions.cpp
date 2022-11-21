//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    vector<vector<int>>vec;

 vector<int>v;

 void fun(int n,int arr[],int i,int s)

 {

     if(s>n || i>=n)

     return ;

     if(s == n)

     {

         vec.push_back(v);

         return ;

     }

     v.push_back(arr[i]);

     fun(n,arr,i,s+arr[i]);

     v.pop_back();

     fun(n,arr,i+1,s);

     

     

 }

    vector<vector<int>> UniquePartitions(int n) {

        // Code here

        int arr[n];

        int i,s=0;

        for(i=1;i<=n;i++)

        arr[i-1]=i;

        i=0;

        // vector<int>v;

        fun(n,arr,i,s);   

        // nothing but lo ya mt lo concept .

        // at 17:43;

        // no DP just recursion. 

        // sort(vec.begin(),vec.end());

        

        for(i=0;i<vec.size();i++)

        {

            sort(vec[i].begin(),vec[i].end(),greater<int>());

        }

        sort(vec.rbegin(),vec.rend());

        return vec;

    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends