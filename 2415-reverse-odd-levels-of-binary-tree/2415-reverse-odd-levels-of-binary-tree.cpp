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
  
  void preOrder(TreeNode *root1, TreeNode* root2, int l) {
    if(!root1 || !root2) return;
    if(l%2 == 0) swap(root1->val, root2->val);
    preOrder(root1->left, root2->right, l+1);
    preOrder(root1->right, root2->left, l+1);
}
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        preOrder(root->left, root->right, 0);
        return root;
    }
};