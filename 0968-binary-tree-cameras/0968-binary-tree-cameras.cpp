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
    int count=0;
    int helper(TreeNode* root)
    {
        if(root==NULL) return 1;
        int l=helper(root->left);
        int r=helper(root->right);
        if(l==0 or r==0)
        {
            count++;
            return 2;
        }
        if(l==2 or r==2)
        {
            return 1;
        }
        return 0; 
    }
    int minCameraCover(TreeNode* root) {
        count=0;
        int a=helper(root);
        if(a==0) return count+1;
        return count;

    }
};