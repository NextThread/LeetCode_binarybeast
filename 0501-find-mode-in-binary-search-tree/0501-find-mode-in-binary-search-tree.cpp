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
    
    // Do, Inorder traversal and store in a vector, all nodes
    // use map, to count frequency of each node value using the vector
    // find out the max freq from the map
    // iterate over the map, and check which node values are havig frequency == mxfreq
    // store those in the result array and return
    
    vector<int>v;
    
    void in(TreeNode* root) {
        if(!root) return;
        in(root->left);
        v.push_back(root->val);
        in(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        in(root); // call the inorder
        
        map<int, int> mp;
        
        vector<int> ans;  // to store and return our answer
        for(int x : v) mp[x]++; // counting frequency of each node values
        
        int mxfreq = -1;
        for(auto it : mp) {
            mxfreq = max(it.second, mxfreq); // looking for max frequency
        }
        for(auto it : mp) {
            if(it.second == mxfreq) { // check which is having frequency == mxfreq
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};