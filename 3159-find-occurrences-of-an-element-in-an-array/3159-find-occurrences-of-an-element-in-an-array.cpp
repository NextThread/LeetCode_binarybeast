class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& a, vector<int>& q, int x) {
      vector<int> v;
      for(int i=0;i<a.size();i++)
        if(a[i] == x) v.push_back(i);
      
      vector<int> ans;
      for(auto i : q)
      {
        if(i>v.size()) ans.push_back(-1);
        else ans.push_back(v[i-1]);
      }    
      return ans;
    }
};