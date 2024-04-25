class Solution {
public:

// Function to find
// the longest Special Sequence
int longestIdealString(string s, int k)
{
	int n = s.size();
	// Creating a list with
	// all 0's of size``
	// equal to the length of string
	vector<int> dp(n, 0);

	// Supporting list with
	// all 0's of size 26 since
	// the given string consists
	// of only lower case alphabets
	int max_length[26] = {0};

	for (int i = 0; i < n; i++)
	{

		// Converting the ascii value to
		// list indices
		int curr = s[i] - 'a';

		// Determining the lower bound
		int lower = max(0, curr - k);

		// Determining the upper bound
		int upper = min(25, curr + k);

		// Filling the dp array with values
		for (int j = lower; j < upper + 1; j++)
		{
			dp[i] = max(dp[i], max_length[j] + 1);
		}
		//Filling the max_length array with max
		//length of subsequence till now
		max_length[curr] = max(dp[i], max_length[curr]);
	}

	int ans = 0;

	for(int i:dp) ans = max(i, ans);

	// return the max length of subsequence
	return ans;
}
};