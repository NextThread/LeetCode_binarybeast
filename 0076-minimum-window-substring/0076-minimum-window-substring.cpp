class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        unordered_map<char,int> map;
        for(int i=0;i<t.size();i++){
            map[t[i]]++;
        }
        int count=0,start=0,min_length = INT_MAX, min_start = 0;
        for(int end=0; end<s.size(); end++){
            if(map[s[end]]>0){
                count++;
            }
            map[s[end]]--; 
            if(count == t.length()) { 
                while(start < end && map[s[start]] < 0){
                    map[s[start]]++, start++;
                } 
                if(min_length > end-start){
                    min_length = end-(min_start=start)+1; 
                }
                map[s[start++]]++; 
                count--;
            }
        }
        return min_length == INT_MAX ? "" : s.substr(min_start, min_length);
    }
};