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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return 0;
        // if(!root) return res;
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
            res.push_back(temp);
        }
        int size = res.size();
        // int last = res[size-1].size();
        return res[size-1].front();
            // [[1, 2, 4], [3], [2, 4]]
    }
};