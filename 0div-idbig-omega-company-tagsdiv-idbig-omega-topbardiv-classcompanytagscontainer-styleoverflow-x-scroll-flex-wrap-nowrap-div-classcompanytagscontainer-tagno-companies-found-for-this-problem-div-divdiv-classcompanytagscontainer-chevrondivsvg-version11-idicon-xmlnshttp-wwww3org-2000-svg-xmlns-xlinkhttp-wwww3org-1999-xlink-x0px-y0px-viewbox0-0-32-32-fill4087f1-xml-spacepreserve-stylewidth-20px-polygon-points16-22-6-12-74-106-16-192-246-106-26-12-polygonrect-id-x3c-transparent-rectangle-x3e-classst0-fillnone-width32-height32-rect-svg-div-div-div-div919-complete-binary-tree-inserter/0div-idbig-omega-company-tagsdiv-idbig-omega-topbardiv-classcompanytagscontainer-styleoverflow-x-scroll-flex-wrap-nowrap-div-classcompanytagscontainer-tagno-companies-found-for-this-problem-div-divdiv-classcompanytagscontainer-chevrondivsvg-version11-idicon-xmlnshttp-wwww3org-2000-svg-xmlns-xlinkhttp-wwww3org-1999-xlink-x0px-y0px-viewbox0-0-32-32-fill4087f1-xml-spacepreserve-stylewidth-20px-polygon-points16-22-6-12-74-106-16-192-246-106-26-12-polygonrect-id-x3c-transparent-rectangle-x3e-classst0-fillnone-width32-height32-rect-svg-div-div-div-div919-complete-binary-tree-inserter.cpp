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
class CBTInserter {
public:
    queue<TreeNode*>q;
    TreeNode* x;
    CBTInserter(TreeNode* root) {
        x=root;
        q.push(root);
    }
    
    int insert(int val) 
    {
        int x;
        while(true)
        {
            TreeNode* temp =  q.front();
        
            if(temp->left==NULL)
            {
                x=temp->val;
                temp->left=new TreeNode(val);
                q.push(temp->left);
                return x;
            }
            else if(temp->left!=NULL and temp->right==NULL)
            {
                q.pop();
                
                x=temp->val;
                temp->right=new TreeNode(val);
                q.push(temp->left);
                q.push(temp->right);
                return x;
            }
            else if(temp->left!=NULL and temp->right!=NULL)
            {
                q.pop();
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        
        return -1;
    }
    
    TreeNode* get_root() {
        return x;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
