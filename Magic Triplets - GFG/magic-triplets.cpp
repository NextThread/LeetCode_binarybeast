//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	       int left, right, l_count, r_count;
	    int res =0;
	    
	    for(int i =1; i< nums.size()-1 ; i++) {
	        left = i-1;
	        right = i+1;
	        r_count = l_count = 0;
	        
	        while(left>=0) {
	            if(nums[left]<nums[i]) {
	                l_count++;
	            }
	            left--;
	        }
	        while(right < nums.size()) {
	            if(nums[right] > nums[i]) {
	                r_count++;
	            }
	            right++;
	        }
	        
	        res += (l_count * r_count);
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends