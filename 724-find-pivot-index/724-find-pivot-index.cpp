class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(begin(nums), end(nums), 0);
		int curSum = 0;
		for (int i = 0 ; i < nums.size() ; i++) {
			if (curSum == total - curSum - nums[i]) return i;
			curSum += nums[i];
		}
		return -1;
    }
};