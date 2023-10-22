class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int n = nums.size();
        
        // left[i] will store the index of next smaller element on left side

        vector<int> left(n, -1);
        
        // right[i] will store the index of next smaller element on right side

        vector<int> right(n, n);
        
        // stack will store the element in decreasing order

        stack<int> st;
        
        // fill the left array

        for(int i = 0; i < n; i++)
        {
            while(st.empty() == false && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            if(st.empty() == false)
            {
                left[i] = st.top();
            }

            st.push(i);
        }
        
        // empty the stack

        while(!st.empty())
        {
            st.pop();
        }
        
        // fill the right array

        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            if(st.empty() == false)
            {
                right[i] = st.top();
            }

            st.push(i);
        }
        
        // find the maximum

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            if(left[i] < k && right[i] > k)
            {
                int width = right[i] - left[i] - 1;

                maxi = max(maxi, nums[i] * width);
            }
        }

        return maxi;
    }
};