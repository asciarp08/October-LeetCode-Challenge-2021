/**
Time = O(n), n = number of nodes
Space = O(n)
**/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
    
    int dfs(TreeNode* root, int& diameter){
        if(root==NULL)
            return 0;
        int leftDepth = dfs(root->left, diameter);
        int rightDepth = dfs(root->right, diameter);
        
        diameter = max(diameter, leftDepth+rightDepth);
        
        return 1+max(leftDepth, rightDepth);
        
            
    }
};
