class Solution {
public:
   void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int cur) {
        path.push_back(cur); // push the cur node
        if (cur == graph.size() - 1) // if we have reached the n-1 node then simply push the path 
            res.push_back(path);
        else for (auto it: graph[cur]) // else call the dfs for all its adjacent
            dfs(graph, res, path, it);
        path.pop_back(); // pop the path
   }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths; // 2D vector to store all the paths from 0 to n-1
        vector<int> path; // to store one valid path from 0 to n-1
        dfs(graph, paths, path, 0); // recursive call
        return paths;
    }
};