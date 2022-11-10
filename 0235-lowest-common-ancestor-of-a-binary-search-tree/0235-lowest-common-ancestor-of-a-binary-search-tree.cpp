/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
         // if root equals to p or q return it
         // left = recursive call for left
         // right = recursive call for right
         // if both are ok return
         // if any one becomes NULL return NULL
         // if left return it else return right
 class Solution {
 public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(right && left) return root;
        if(!right && !left) return NULL;
        return left?left:right;
     }
 };