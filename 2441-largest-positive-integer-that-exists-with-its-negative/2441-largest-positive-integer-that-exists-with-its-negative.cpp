class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = INT_MIN;
       for(int i = 0 ; i < nums.size() ; i++)
       {
         for(int j = 0 ; j < nums.size() ; j++)
         {
           if(nums[i] == -nums[j]) res = max(res, abs(nums[i]));
         }
       }
      if(res == INT_MIN) return -1;
      return res;
    }
};