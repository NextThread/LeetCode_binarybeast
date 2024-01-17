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
TreeNode* createBinaryTree(vector<vector<int>>& des)     {
        unordered_set<int> k; 
        unordered_map<int, TreeNode*> bank;
		for(int i =0; i<des.size(); i++)
        {
            k.insert(des[i][0]);
            k.insert(des[i][1]);
            
            if(bank.find(des[i][0]) == bank.end())
            {
                TreeNode *temp = new TreeNode(des[i][0]);
                bank.insert({des[i][0], temp});
            }
            if(bank.find(des[i][1]) == bank.end())
            {
                TreeNode *temp = new TreeNode(des[i][1]);
                bank.insert({des[i][1], temp});  
            }
            
            if(des[i][2] == 0)
                bank[des[i][0]]->right = bank[des[i][1]];
            else
                bank[des[i][0]]->left = bank[des[i][1]];
        }
        
        for(int i =0; i<des.size(); i++)
            k.erase(k.find(des[i][1]));
        
        return bank[*k.begin()];
    }
};