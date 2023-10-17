
class Solution {
public:
    void traverseTree(vector<int> &left, vector<int> &right, int root, vector<bool> &vis) {
        if(root==-1 || vis[root]==true){
            return;
        }
        vis[root]=true;
        traverseTree(left,right,left[root],vis);
        traverseTree(left,right,right[root],vis);
        return;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n,0);
        for (int i=0;i<n;i++) {
            if(leftChild[i]!=-1 && ++indegree[leftChild[i]]>1){ //if incoming edges exceed 1, not possible
                return false;
            }
            if(rightChild[i]!=-1 && ++indegree[rightChild[i]]>1){
                return false;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(root!=-1){  // we see more than 1 root, not possible, return false
                    return false;
                }
                root=i;
            }
        }        
        if(root==-1){  //if root is still -1 there is no root, return false
            return false;
        }
        vector<bool> vis(n,false);
        traverseTree(leftChild,rightChild,root,vis);
        for(auto e: vis){
            if(e==false){  //this node is left unvisited and hence not a valid tree, return false 
                return false;
            }
        }
        return true; 
    }
};