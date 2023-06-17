class Solution {
    int dp[2001][2001][2];
public:
    int getMin(vector<int>&arr1, vector<int>&arr2, int i, int j, int prev, bool flag) {
        if(i == arr1.size()) return 0;
        if(dp[i][j][flag] != -1) return dp[i][j][flag];
        
        while(j < arr2.size() && arr2[j] <= prev) j++;
        
        if(arr1[i] <= prev && j == arr2.size()) return 2001;
        
        int take = 2001;
        int ignore = 2001;
        if(j != arr2.size()) take = 1 + getMin(arr1, arr2, i + 1, j + 1, arr2[j], false);
        if(arr1[i] > prev) ignore = getMin(arr1, arr2, i + 1, j, arr1[i], true);
        
        return dp[i][j][flag] = min(take, ignore);
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        memset(dp, -1, sizeof(dp));
        
        int temp = getMin(arr1, arr2, 0, 0, -1, true);
        if(temp > arr1.size()) return -1;
        
        return temp;
    }
};