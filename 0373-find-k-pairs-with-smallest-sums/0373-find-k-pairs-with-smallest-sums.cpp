class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
            int n1 = nums1.size(), n2 = nums2.size();  vector<vector<int>> ans;
        
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minheap;
        
            for(int i=0; i<n1; i++)
                minheap.push({nums1[i] + nums2[0], {i,0}});
        
            while(ans.size() < k && !minheap.empty()){
                
                pair<int, pair<int, int>> p = minheap.top();
                minheap.pop();
                
                int i = p.second.first, j = p.second.second;
                ans.push_back({nums1[i],nums2[j]});
                         
                if(j+1 < n2){
                    minheap.push({nums1[i]+nums2[j+1], {i, j+1}});
                }
        }
        return ans;
    }
};