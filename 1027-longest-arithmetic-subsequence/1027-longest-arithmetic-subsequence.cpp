class Solution {
public:
     int longestArithSeqLength(vector<int>& A) {
	int len = A.size();
	int maxLen = 1;
	vector<vector<int>> dp(A.size(), vector<int>(1001, 1));
	for (int i = 1; i < A.size(); i++) {
		for (int j = 0; j < i; j++) {
			int index = A[i] - A[j] + 500;
			dp[i][index] = max(dp[i][index], dp[j][index] + 1);
			maxLen = max(maxLen, dp[i][index]);
		}
	}
	return maxLen;
}
};