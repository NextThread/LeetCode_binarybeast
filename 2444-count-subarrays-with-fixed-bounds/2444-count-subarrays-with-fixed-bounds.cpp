#define ll long long
class Solution {
public:
    // const int mod = 1e10+7;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       int n = nums.size();
        int leftBound = -1;
        int lastMin = -1, lastMax = -1;
        ll count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                lastMin = (nums[i] == minK) ? i : lastMin;
                lastMax = (nums[i] == maxK) ? i : lastMax;
                count += max(0, min(lastMin, lastMax) - leftBound);
            }
            else {
                leftBound = i;
                lastMin = -1;
                lastMax = -1;
            }
        }
        return count; 
    }
};