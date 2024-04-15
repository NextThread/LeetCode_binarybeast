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
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;      // {node, cur}
        s.push({root, 0});
        int sum = 0;
        while(!s.empty()) {
            auto [root, cur] = s.top(); s.pop();
            cur = cur * 10 + root -> val;
            if(!root -> left && !root -> right) sum += cur;  // reached leaf node
            if(root -> right) s.push({root -> right, cur});
            if(root -> left) s.push({root -> left, cur});
        }
        return sum;
    }
};