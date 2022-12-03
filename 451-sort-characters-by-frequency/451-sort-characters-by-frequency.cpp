class Solution {
public:
    
    static bool cmp(pair<char,int>&a, pair<char,int>&b) { // comparator, which we are going to use to sort our map
        return a.second>b.second;
    }
    
    string frequencySort(string s) {
        if(s.length() < 2) return s; // base case
        unordered_map<char, int> mp; // map to store the frequency of each character
        for(char ch : s) mp[ch]++; // count the frequency of each character
        vector<pair<char,int>> freq_pair; // we are going to store the {char, freq} pair in a vector, so that we can sort it using our comparator.
        for(auto pairs : mp) freq_pair.push_back(pairs); // store in the vector
        sort(freq_pair.begin(), freq_pair.end(), cmp); // sort the vector
        string ans = "";
        for(auto f : freq_pair) { // iterate on the vector, and keep adding chars into our ans string, and then return the string
            for(int i = 0 ; i < f.second ; i++) {
                ans += f.first;
            }
        }
        return ans;
    }
};
