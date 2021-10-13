/**
Time = O(n)
Space = O(n)
**/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int idx = 0;
        return constructBST(preorder, n ,idx, INT_MIN, INT_MAX);
    }
    
    TreeNode* constructBST(vector<int>& preorder, int& n, int& idx, int lower, int upper){
        
        if(idx==n || preorder[idx]>upper || preorder[idx]<lower)
            return NULL;
        
        TreeNode* cur = new TreeNode(preorder[idx++]);
        cur->left = constructBST(preorder, n, idx, lower, cur->val-1);
        cur->right = constructBST(preorder, n, idx, cur->val+1, upper);
        
        return cur;
            
    }
};
