class Solution {
public:
    
    static bool cmp(pair<char,int>&a, pair<char,int>&b) {
        return a.second>b.second;
    }
    
    string frequencySort(string s) {
        if(s.length()<2) 
            return s;
        map<char,int> mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        vector<pair<char,int>> freq_pair;
        for(auto m: mp) {
            freq_pair.push_back(m);
        }
        sort(freq_pair.begin(),freq_pair.end(),cmp);
        string ans;
        for(auto f : freq_pair) {
            for(int i=0;i<f.second;i++) {
                ans += f.first;
            }
        }
        return ans;
    }
};
