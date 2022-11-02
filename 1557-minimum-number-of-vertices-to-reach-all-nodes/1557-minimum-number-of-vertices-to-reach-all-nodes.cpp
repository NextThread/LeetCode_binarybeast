class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
     vector<int>seen(n,0); // use the vector as a visited array
        vector<int>ans; // where we are going to store the node values
        for(auto it : edges){
            seen[it[1]] = 1; // make it visited, the 2nd node of each pair because its a directed graph, we can go only edges[i][0]  to edges[i][1]
        }
        for(int i = 0 ; i < n ; i++){ 
            if(!seen[i]) ans.push_back(i); // if any node has not been visited yet push it into the resultant arry
        }
        return ans;
    }
};