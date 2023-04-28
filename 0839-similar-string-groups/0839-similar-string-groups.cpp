class Solution {
public:
    bool sameORnot(string s1, string s2) 
    {
        int cnt = 0;
        for(int i = 0; i < s1.length(); i++) 
        {
            cnt += (s1[i] != s2[i]);
        }
        return (cnt == 2 || cnt == 0);
    }
    
    void dfs(vector<string> &strs, vector<bool> &vis, int ind) 
    {  
        vis[ind] = true;
        string curr = strs[ind];
        for(int i = 0 ; i < strs.size() ; i++)
        {     
            if(!vis[i] && sameORnot(curr, strs[i]))
            {
                dfs(strs, vis, i);
            }      
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
       int n = strs.size();
        vector<bool> vis(n, false);
        int res = 0;
        for(int i = 0 ; i < n ; i++) 
        {
            if(!vis[i]) 
            {
                res++;
                dfs(strs, vis, i);
            }
        }
        return res;
    }
};