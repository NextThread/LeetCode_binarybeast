class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1;
        vector<vector<int>> res;
        vector<int> v1, v2;
        map<int, int> mp2;
        for(int x : nums1) {
            mp1[x]++;
        }
        for(int x : nums2) {
            if(mp1.find(x) == mp1.end()) v1.push_back(x);
        }
        for(int x : nums2) {
            mp2[x]++;
        }
        for(int x : nums1) {
            if(mp2.find(x) == mp2.end()) v2.push_back(x);
        }
        set<int> st;
        for(int x : v1) st.insert(x);
        v1.clear();
        for(auto it : st) v1.push_back(it);
        set<int> st1;
        for(int x : v2) st1.insert(x);
        v2.clear();
        for(auto it : st1) v2.push_back(it);
        res.push_back(v2);
        res.push_back(v1);
        return res;
    }
};