class Solution {
    void dfs(TreeNode* leftNode, TreeNode* rightNode, int level){
        if(!leftNode || !rightNode) return;

        if(level % 2) swap(leftNode->val, rightNode->val);

        dfs(leftNode->left, rightNode->right, level+1);
        dfs(leftNode->right, rightNode->left, level+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }
};