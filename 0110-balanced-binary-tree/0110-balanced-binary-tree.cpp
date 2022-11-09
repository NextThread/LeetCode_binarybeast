// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
	// public:
	// 	int height(TreeNode *root) {
	// 		if(!root) return 0;
	// 		return max(height(root->left), height(root->right)) + 1;
	// 	}
	// 	bool isBalanced(TreeNode* root) {
	// 		if(!root) return true;
	// 		return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
	// 	}
// };
class Solution {
public:
    int f(TreeNode* root)
    {
      if(!root) return 0;
      return max(f(root->left), f(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(f(root->left) - f(root->right)) <= 1;
    }
};