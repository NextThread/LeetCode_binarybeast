class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
          vector<int>start,end,ans;
        for(auto x:flowers){
            start.push_back(x[0]);
            end.push_back(x[1]);
        }
        sort(start.begin(),start.end()),sort(end.begin(),end.end());
        for(auto x:people){
            int t=x;
            int idx1=upper_bound(start.begin(),start.end(),t)-start.begin();
            int idx2=lower_bound(end.begin(),end.end(),t)-end.begin();
            ans.push_back(idx1-idx2);
        }
        return ans;
    }
};