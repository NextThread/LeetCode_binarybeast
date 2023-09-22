class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
         unordered_map<int,vector<int>> mp;
    
    for(auto x: pieces)
    {
        mp[x[0]] = x;
    }
    
    vector<int> res;
    
    for(auto x: arr)
    {
       if(mp.find(x) != mp.end()) 
       {
           res.insert(res.end(), mp[x].begin(),mp[x].end());
       }
    }
    
    return res == arr;
    }
};