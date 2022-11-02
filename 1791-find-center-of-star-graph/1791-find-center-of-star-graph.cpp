class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
    map<int, int>mp;
    for(auto it : edges) 
    {
      mp[it[0]]++;
      mp[it[1]]++;
    }
      for(auto it : mp) cout<<it.first<<" occurs "<<it.second<<endl;
    int mxfreq = -1;
    for(auto it : mp) mxfreq = max(mxfreq, it.second);
    int res = -1;
    for(auto it : mp) if(it.second == mxfreq) res = it.first;
    // return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    return res;
    }
};