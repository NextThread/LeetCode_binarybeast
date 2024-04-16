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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
      if (depth == 0 || depth == 1) {
            TreeNode* newroot = new TreeNode(val);
            (depth ? newroot->left : newroot->right) = root;
            return newroot;
        }
        if (root && depth >= 2) {
            root->left  = addOneRow(root->left,  val, depth > 2 ? depth - 1 : 1);
            root->right = addOneRow(root->right, val, depth > 2 ? depth - 1 : 0);
        }
        return root;   
    }
};