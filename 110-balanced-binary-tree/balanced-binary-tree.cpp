int findHeights(TreeNode* root) {
    if (!root) return 0; 
    return 1 + max(findHeights(root->left), findHeights(root->right)); 
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true; 
        
        int diff = abs(findHeights(root->left) - findHeights(root->right)); 
        if (diff > 1) return false; 
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
