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
    
    // void inorder(TreeNode* root, vector<int> &res)
    // {
    //     if(!root) return;
    //     if(root->left) inorder(root->left, res);
    //     res.push_back(root->val);
    //     if(root->right) inorder(root->right, res);
    // }
    
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int> res;
     stack<TreeNode*> st;
     TreeNode* curr = root;
        while(!st.empty() or curr)
        {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                curr = st.top();
                st.pop();
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
     return res;
    }
};