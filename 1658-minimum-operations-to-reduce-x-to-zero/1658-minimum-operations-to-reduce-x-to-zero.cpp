class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size(), s = 0, ans = 1000000;
        
        for(int i = 0; i < n ; i++) s += nums[i];
        
        if(s < x) return -1;
        
        int st = 0, end = 0, windowSum = 0;
        
        while(end < n){            
            windowSum += nums[end];            
            while(windowSum > (s - x)){
                windowSum -= nums[st]; //Reducing window size
                st++;
            }            
            if(windowSum == s - x){
                ans = min(ans, n - (end - st + 1));
            }            
            end++;            
        }
		
        return (ans == 1000000 ? -1 : ans);
        
    }
};