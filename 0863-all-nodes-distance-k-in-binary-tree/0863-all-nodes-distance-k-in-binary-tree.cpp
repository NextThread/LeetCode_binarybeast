/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int,vector<int>> lev_node;
    void dfs(int node,int d,vector<int> adj[],vector<int>& vis,vector<int>& dis) {
        lev_node[d].push_back(node);
        vis[node]=1;
        for(auto x: adj[node]) {
            if(!vis[x]) {
                dfs(x,d+1,adj,vis,dis);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> adj[505];
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left) {
                adj[cur->val].push_back(cur->left->val);
                adj[cur->left->val].push_back(cur->val);
                q.push(cur->left);
            }
            if(cur->right) {
                adj[cur->val].push_back(cur->right->val);
                adj[cur->right->val].push_back(cur->val);
                q.push(cur->right);
            }


        }
        vector<int> dis(505,0), vis(505,0);
        dfs(target->val,0,adj,vis,dis);
        vector<int> res;
        for(auto it: lev_node[k])
            res.push_back(it);
        return res;      
    }
};