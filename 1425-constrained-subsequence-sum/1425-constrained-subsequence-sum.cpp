class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int maxSum = nums[0];
        deque<int> maxSumQueue;

        for (int i = 0; i < nums.size(); i++) {
            nums[i] += !maxSumQueue.empty() ? maxSumQueue.front() : 0;
            maxSum = max(maxSum, nums[i]);

            while (!maxSumQueue.empty() && nums[i] > maxSumQueue.back()) {
                maxSumQueue.pop_back();
            }

            if (nums[i] > 0) {
                maxSumQueue.push_back(nums[i]);
            }

            if (i >= k && !maxSumQueue.empty() && maxSumQueue.front() == nums[i - k]) {
                maxSumQueue.pop_front();
            }
        }

        return maxSum;
    }
};