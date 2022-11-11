class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int f = 1 , s = 1;
        while(f < nums.size()){
            if(nums[f-1] != nums[f]) { // means we are having adjacent elements that aren't duplicate
              nums[s] = nums[f]; // so increase the slow pointer for the new array and store the duplicate in the new array
              s++;
            }
            f++;
        }
        return s;
    }
};