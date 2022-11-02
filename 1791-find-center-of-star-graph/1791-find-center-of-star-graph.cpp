class Solution {
public:
    
    // we just need to check which node is having the highest degree
    
    int findCenter(vector<vector<int>>& edges) {
    map<int, int>mp; // map to store count the degree of nodes
    for(auto it : edges) 
    {
      mp[it[0]]++; // increment the degree of 1st node of the pair
      mp[it[1]]++; // increment the degree of 2nt node of the pair
    }
    int mxfreq = -1;
    for(auto it : mp) mxfreq = max(mxfreq, it.second); // get the maximum degree from the map
    int res = -1;
    for(auto it : mp) if(it.second == mxfreq) res = it.first; // check which node is having the maximum degree
    return res; // return it
    }
};