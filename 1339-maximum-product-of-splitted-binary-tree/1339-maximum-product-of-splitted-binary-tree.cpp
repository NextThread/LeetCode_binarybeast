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
    long long ans = 0, totalSum = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int currSum = dfs(root->left) + dfs(root->right) + root->val;
        ans = max(ans, (totalSum - currSum) * currSum);
        return currSum;
    }
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root); // Firstly, get total sum of all nodes in the Binary Tree
        dfs(root); // Then dfs in post order to calculate sum of each subtree and its complement
        return ans % int(1e9+7);
    }
};