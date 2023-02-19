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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*>q;
        bool left_to_right = true;
        q.push(root);
        if(!root) return res;
        while(q.size())
        {
            int size = q.size();
            vector<int> temp(size);
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(left_to_right) temp[i] = node->val;
                else temp[size-i-1] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            left_to_right = !left_to_right;
            res.push_back(temp);
        }
        return res;
    }
};