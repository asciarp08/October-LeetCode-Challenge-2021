/**
Time = O(logn*logn); n = number of nodes
Space = O(logn)
**/
class Solution {
public:
    int countNodes(TreeNode* root) {
        int nodes = 0;
        
        while(root!=NULL){
            int lh = height(root->left);
            int rh = height(root->right);
            if(lh==rh){
                nodes+=(1<<lh);
                root = root->right;
            }
            else{
                nodes+=(1<<rh);
                root = root->left;
            }
        }
        return nodes;
    }
           
    int height(TreeNode* root){
        return root==NULL?0:1+height(root->left);
    }
};
