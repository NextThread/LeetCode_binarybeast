class Solution {
public:
    void solving(vector<int>& nums, vector<vector<int>>& output, vector<int>& temp, int index){
        if(index >= nums.size()){ // base case
            if(temp.size() > 1) output.push_back(temp);
            return;
        }
        if(index == 0 || temp.size() == 0 || nums[index] >= temp[temp.size()-1]){ // if we met the condition
            temp.push_back(nums[index]); // store the subset in our res
            solving(nums, output, temp, index+1); // recursive call for next index
            temp.pop_back(); // pop the last one, so that we can backtrack from the last location
        }
        if(temp.size() == 0 || temp[temp.size()-1] != nums[index]) {
            solving(nums, output, temp, index+1);
        }
    }
	
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> output; // where we are going to store the subsets to return it
        vector<int> temp;
        solving(nums, output, temp, 0); // dfs call
        return output;
    }
};