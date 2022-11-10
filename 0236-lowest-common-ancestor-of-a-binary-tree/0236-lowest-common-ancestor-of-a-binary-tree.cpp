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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL; // base case : if root is NULL
        if(root == p || root == q) return root; // base case : if root is equal to p or q
        TreeNode* left = lowestCommonAncestor(root->left, p, q); // recursive call for left
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // recursive call for right
        if(right && left) return root;
        if(!right && !left) return NULL;
        return left?left:right;
    }
};