/**
Time = O(n)
Space = O(n)
**/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        invert(root);
        return root;
    }
    
    void invert(TreeNode* root){
        
        if(root==NULL)return;
        
        swap(root->left, root->right);
        
        invert(root->left);
        invert(root->right);
    }
};
