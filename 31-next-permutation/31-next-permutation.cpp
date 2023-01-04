class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        /*      STL

                next_permutation(begin(nums), end(nums));

        */

        /*
            auto i = is_sorted_until(nums.rbegin(), nums.rend());
            if (i != nums.rend())
                swap(*i, *upper_bound(nums.rbegin(), i, *i));
            reverse(nums.rbegin(), i);
        */

        //        Algorithm:

        // step 1: Linearly traverse given array from the end and find a number that is greater than its adjacent nums[i] > nums[i-1]. Store the index of smaller number in breakPoint variable. If there is no such element, reverse entire array and return.

        // step 2: Linearly traverse from the end and this time find a number larger than nums[breakPoint]. Let's call it nums[i].

        // step 3: Swap nums[i] and nums[breakPoint].

        // step 4: Reverse the array from index breakPoint + 1 to nums.size().
        int n = nums.size();
        int breakpoint = -1;
        for (int i = n - 1; i >= 1; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                breakpoint = i-1;
                break;
            }
        }
        if (breakpoint == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int larger, ind;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[breakpoint])
            {
                larger = nums[i];
                ind = i;
                break;
            }
        }
        swap(nums[ind], nums[breakpoint]);
        reverse(nums.begin() + breakpoint + 1, nums.end());
    }
};