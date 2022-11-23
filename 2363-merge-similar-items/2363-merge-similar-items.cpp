class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
      
      
      // intuition
      
      // first store the 1st array in a map
      // next time while iterating on the second array
      // check if the item is already there in the map, if it is,
      // then increase its count, else push in the map as a new element
      // lastly in a 2d vector, insert the element with their values from the map
      // return the 2d vector
      
      map<int, int>mp;
      for(int i = 0 ; i < items1.size() ; i++)
      {
        mp[items1[i][0]] = items1[i][1];
      }
      for(int i = 0 ; i < items2.size() ; i++)
      {
        if(mp.find(items2[i][0]) != mp.end()) mp[items2[i][0]] += items2[i][1];
        else mp[items2[i][0]] = items2[i][1];
      }
      
    // for debugging 
    // for(auto it : mp) cout<<it.first<<" "<<it.second<<endl;
      
      vector<vector<int>> res;
      for(auto it : mp)
      {
        res.push_back({it.first, it.second});
      }
      return res;
    }
};
