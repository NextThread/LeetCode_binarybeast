class Solution {
public:
    int findDuplicate(vector<int>& nums) {
           int ind = 0;
		
		// sort the vector
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 1; i++)
        {
			// if two consecutive elements are equal
			// you have find a duplicate
			// break the loop
            if(nums[i] == nums[i+1])
            {
                ind = nums[i];
                break;
            }
        }
        // return duplicate value
        return ind;
    }
};