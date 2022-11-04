class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int>>res;
    if(num.size() < 3) return res;
    set<vector<int>> st;
    for(int i = 0 ; i < num.size()-2 ; i++)
    {
        int val = num[i];
        int lo = i+1;
        int hi = num.size()-1;
        while(lo < hi)
        {
            if(val+num[lo]+num[hi] == 0)
            {
                st.insert({val, num[lo], num[hi]});
                lo++,hi--;
            }
            else if(val+num[lo]+num[hi] < 0) lo++;
            else hi--;
        }
    }
    for(auto it : st) res.push_back(it);
    return res;
    }
};