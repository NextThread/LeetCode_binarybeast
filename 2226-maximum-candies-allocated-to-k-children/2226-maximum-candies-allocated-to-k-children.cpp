class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        // Intution-
        // we can have maximum assign candies is, total candies by no of childs, i.e. size of candies array
        // now we just need to take care of 2 conditions, focusing on k
        // either it can be greater than k or less than k
        // so we will be applying binary search
        int left = 0, right = 1e7+1;
        while (left < right) {
            long sum = 0;
            long mid = (left + right + 1) / 2;
            for (auto it : candies) {
                sum += (it / mid);
            }
            if (k > sum)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
};