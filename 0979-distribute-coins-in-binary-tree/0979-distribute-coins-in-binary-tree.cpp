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
    int ans = 0;
    int recr(TreeNode *root)
    {
        if(!root) return 0;
        int left = recr(root->left);
        int right = recr(root->right);
        int curr = root->val + left + right;
        ans += abs(curr-1);
        return curr-1;
    }
    int distributeCoins(TreeNode* root) {
        recr(root);
        return ans;
    }
};