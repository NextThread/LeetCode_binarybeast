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
  
    int f(TreeNode* root, int &d)
    {
      if(!root) return 0;
      int ld = f(root->left, d);
      int rd = f(root->right, d);
      d = max(d, ld+rd);
      return max(rd, ld)+1;
    }
  
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        f(root, d);
        return d;
    }
};