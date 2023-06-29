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
        // same as level order, just include a variable
        // to change direction at each level
       vector<vector<int>> res;
        bool ltr = true;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int size = q.size();
            vector<int> temp(size);
            for(int i = 0 ; i < size ; i++) { 
                TreeNode* cur = q.front();
                q.pop();
                temp[i] = cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(!ltr) {
                ltr = !ltr;
                reverse(temp.begin(), temp.end());
            }
            else {
                ltr = !ltr;
            }
            res.push_back(temp);
        }
        return res; 
    }
};