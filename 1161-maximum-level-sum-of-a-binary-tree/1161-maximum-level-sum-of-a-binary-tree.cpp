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
    int maxLevelSum(TreeNode* root) {
       int lvl = 1;
        int sum = 0;
        queue<TreeNode*> q;
        int mx = root->val;
        q.push(root);
        int ind = 0;
        while(q.size()) {
            ind++;
            int size = q.size();
            vector<int> temp;
            for(int i = 0 ; i < size ; i++) {
                TreeNode* t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);   
                temp.push_back(t->val);
            }
            sum = accumulate(temp.begin(), temp.end(), 0);
            if(sum > mx) {
                mx = sum;
                lvl = ind;
            }
        }
        return lvl;
    }
};