class Solution {
public:
    
    void toposort(int v, vector<vector<int>> &alist, vector<int> &visited, vector<int> * mp, int &ans, vector<int>&group, vector<vector<int>>&glist){
        if(visited[v] == 1 || ans == -1){
            ans = -1;
            return;
        }
        visited[v] = 1;
        for(int child : alist[v]){
            if(visited[child]!=2)
                toposort(child, alist, visited, mp, ans, group, glist);
            if(group[v]!=group[child])
                    glist[group[v]].push_back(group[child]);
        }
        visited[v] = 2;
        mp[group[v]].push_back(v);
    }
    
    void gTopoSort(int g, vector<vector<int>> & glist, vector<int>&visited, vector<int> & gorder, int &ans){
        if(visited[g]== 1 || ans == -1){
            ans = -1;
            return;
        }
        visited[g] = 1;
        for(int child : glist[g])
            if(visited[child]!=2)
                gTopoSort(child, glist, visited, gorder, ans);
        visited[g] = 2;
        gorder.push_back(g);
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int ans = 0;
        for(int i =0; i<n; i++)
            if(group[i]<0)
            group[i] = m++;
        vector<int> visited(n, 0);
        
        vector<int>mp[m];
        vector<vector<int>> glist(m, vector<int>());
        for(int i =0; i<n; i++) // 1st
            if(!visited[i])
                toposort(i, beforeItems, visited, mp, ans, group, glist);
        if(ans == -1)
            return {};
        
        vector<int>gOrder;
        visited.assign(m, 0);
        ans =0;
        for(int i =0; i<m; i++) // 2nd
            if(!visited[i])
                gTopoSort(i, glist, visited, gOrder, ans);
        if(ans == -1)
            return {};
        
        vector<int>finalAns;
        for(int gp : gOrder)
            finalAns.insert(finalAns.end(), mp[gp].begin(), mp[gp].end());
        return finalAns;
    }
};