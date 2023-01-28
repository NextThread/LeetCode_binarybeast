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
    
    void preorder(TreeNode* root, vector<int> &v)
    {
        if(!root) return;
        v.push_back(root->val);
        if(root->left) preorder(root->left, v);
        if(root->right) preorder(root->right, v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int>v;
        // preorder(root, v);
        // return v;
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (!st.empty() or curr)
        {
            if (curr)
            {
                res.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        return res;
    }
};