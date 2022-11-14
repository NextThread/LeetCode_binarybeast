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
    int max_path_sum = INT_MIN;
    int max_gain(TreeNode* root){
        if(!root) return 0;
        int left_gain = max(max_gain(root->left),0); // including 0, because node values can be negative
        int right_gain = max(max_gain(root->right),0);
        int new_sum = root->val + left_gain + right_gain;
        max_path_sum = max(max_path_sum , new_sum);
        return root->val + max(left_gain , right_gain);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_path_sum;
    }
};