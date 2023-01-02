class Solution
{
public:
    int trap(vector<int> &heights)
    {
        int n = heights.size();
        int water = 0;
        vector<int> left(n, 0), right(n, 0);
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], heights[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], heights[i + 1]);
        for (int i = 1; i < n - 1; i++)
        {
            water += max(0, min(left[i], right[i]) - heights[i]);
        }
        return water;
    }
};