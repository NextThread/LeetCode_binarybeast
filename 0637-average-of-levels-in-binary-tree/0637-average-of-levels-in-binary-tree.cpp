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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<double>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int size = q.size();
            vector<double> temp(size);
            for(int i = 0 ; i < size ; i++) { 
                TreeNode* cur = q.front();
                q.pop();
                temp[i] = cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(temp);
        }
        vector<double> ans;
        for(int i = 0 ; i < res.size() ; i++) {
            double sum = 0;
            for(int j = 0 ; j < res[i].size() ; j++) {
                sum += res[i][j];
            }
            ans.push_back(sum/res[i].size());
        }
        return ans;
    }
};