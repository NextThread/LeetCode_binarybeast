class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char,int>mp;
        int i=0;
        int ans=0;
        for(int j=0;j<s.size();j++)
        {
            mp[s[j]]++;
            while(1)
            {
                int maxF=0;
                for(auto it:mp)maxF=max(maxF,it.second);
                if(maxF>2)
                {
                    mp[s[i]]--;
                    i++;
                }
                else break;
            }
                
                
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};