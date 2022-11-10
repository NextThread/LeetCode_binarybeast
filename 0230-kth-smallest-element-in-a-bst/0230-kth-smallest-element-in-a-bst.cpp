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
    
    //brute force
    // accepted solution
    
//     vector<int>ans;
//     vector<int> inorderTraversal(TreeNode* tr) {
//         if(!tr) return ans;
//     if(tr->left) inorderTraversal(tr->left);
//     ans.push_back(tr->val);
//     if(tr->right) inorderTraversal(tr->right);
//         return ans;
//     }
    
//     int kthSmallest(TreeNode* root, int k) {
//     inorderTraversal(root);
//     sort(ans.begin(), ans.end());
//         return ans[k-1];
//     }
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
       // void Smallestkth(TreeNode* root, int k,vector<int> &vSmallest){
       // if(root->left) Smallestkth(root->left,k,vSmallest);
       // vSmallest.push_back(root->val);
       // if(root->right) Smallestkth(root->right,k,vSmallest);
       // }
  
    priority_queue<int> pq;
    void fun(TreeNode* root, int k)
    {
        if(!root) return;
        pq.push(root->val);
        if(pq.size() == k+1) pq.pop();
        fun(root->left,k);
        fun(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        fun(root,k);
        return pq.top();
    }
};