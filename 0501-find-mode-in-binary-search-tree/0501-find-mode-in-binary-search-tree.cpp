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
    
    vector<int>v;
    
    void in(TreeNode* root) {
        if(!root) return;
        in(root->left);
        v.push_back(root->val);
        in(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        in(root);
        map<int, int> mp;
        vector<int> ans;
        for(int x : v) mp[x]++;
        int mxfreq = -1;
        for(auto it : mp) {
            mxfreq = max(it.second, mxfreq);
        }
        for(auto it : mp) {
            if(it.second == mxfreq) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};