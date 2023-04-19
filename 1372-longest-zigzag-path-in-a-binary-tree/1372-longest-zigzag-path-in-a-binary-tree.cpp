/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int l , int r, int& ans){
        if(!root) return;
         ans = max(ans, l);
         ans = max(ans, r);
        dfs(root->left, 0, l+1, ans);
        dfs(root->right, r+1, 0, ans);
        return;
    }
    int longestZigZag(TreeNode* root) {
        int l = 0, r = 0;
        int res = 0;
        dfs(root, l, r, res);
        return res;
    }
};