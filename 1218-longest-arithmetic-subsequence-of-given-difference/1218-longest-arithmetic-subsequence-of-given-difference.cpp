class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        vector<int> diffArr(40001, 0);
        int ans = 1;
        for (int i : arr)
        {
            diffArr[i + 20000] = diffArr[i - diff + 20000] + 1;
            ans = max(ans, diffArr[i + 20000]);
        }
        return ans;
    }
};