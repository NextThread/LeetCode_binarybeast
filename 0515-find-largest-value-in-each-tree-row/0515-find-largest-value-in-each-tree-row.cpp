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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> res;
        
        if(root == NULL) return {};
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.size() > 0) {
            int size = q.size();
            
            vector<int> temp;
            
            for(int i = 0 ; i < size ; i++) {
                TreeNode* f = q.front();
                q.pop();
                
                if(f->left != NULL) q.push(f->left);
                if(f->right != NULL) q.push(f->right);
                
                temp.push_back(f->val);
            }
            
            res.push_back(temp); 
        }
        vector<int> ans;
        for(int i = 0 ; i < res.size() ; i++) {
            ans.push_back(*max_element(res[i].begin(), res[i].end()));
        }
        return ans;
    }
};