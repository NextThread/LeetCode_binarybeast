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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        // same to same 
//      level order ka code paste krdo
//      bas last m vector ko reverse krdena h
//      yaha pr, level wise niche se upar print krna h, isliye
        
        vector<vector<int>> res;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> temp;
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                TreeNode* now = q.front();
                q.pop();
                if(now->left) q.push(now->left);
                if(now->right) q.push(now->right);
                temp.push_back(now->val);
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};