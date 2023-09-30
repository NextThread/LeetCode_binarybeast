class Solution {
public:
    bool find132pattern(vector<int>& nums) {
         int n=nums.size();
        int mini[n];
		//mini at any position will be our candidate for s1
        mini[0]=nums[0];
        for(int i=1;i<n;i++)
            mini[i]=min(mini[i-1], nums[i]);
        stack<int> st;
        for(int j=n-1;j>=0;j--){ //nums[j] will be our candidate for s2
            if(nums[j]>mini[j]){ //s1<s2
                while(!st.empty() && st.top()<=mini[j]){ //discarding all elements right to s2 which are smaller than s1 as we need s3>s1
                    st.pop();
                }
                if(!st.empty() && st.top()<nums[j]) //now st.top() is our candidate for s3 and we have ensured s1<s3<s2
                    return true;
                st.push(nums[j]);
            }
        }
        return false;
    }
};