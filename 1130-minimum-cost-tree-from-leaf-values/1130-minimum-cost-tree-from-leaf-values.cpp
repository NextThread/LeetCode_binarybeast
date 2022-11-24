class Solution {
public:
    
    // Intuition -
 /*   we have two choices, either keep filling the tree from the left, 
     i.e. use the current node, or keep it to link it with the next upper root node
    
     we'll check both the strategy and take out the minimum one. That's it
 */
    
     int f(vector<int>&arr, int low, int high, vector<vector<int>> &dp)
     {
        if(low == high) return 0; // base case
        if(dp[low][high] != -1) return dp[low][high]; // check if already stored in our dp array
        priority_queue<int> pq(arr.begin()+low, arr.begin()+high+1); // used to take out the maximum one
        int a = pq.top(); // store the top element in a
        pq.pop();  // pop it
        int b = pq.top(); // store the current top element in b
        pq.pop();  // pop it
        int maxProduct = a*b; // max of the top 2 elements that has been stored earlier
        int minSum = INT_MAX;
        for(int i = low ; i < high ; i++)
        {
            minSum = min(minSum, f(arr, low, i, dp) + f(arr, i+1, high, dp)); // check for both the ways
        }
        return dp[low][high] = minSum + maxProduct; // update the dp[low][high]
    }
    int mctFromLeafValues(vector<int>& arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(arr, 0, n-1, dp);
    }
};