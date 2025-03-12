class Solution {
public:
    int level(TreeNode* root){
        if(root == NULL) return 0;  
        return 1 + max(level(root->left), level(root->right));
    }

    bool findVal(TreeNode* root, int cur, int level, int x, int y, int &xpos, int &ypos, TreeNode* &xparent, TreeNode* &yparent, TreeNode* parent){
        if(root == NULL) return false;

        if(root->val == x){
            xpos = cur;
            xparent = parent;
        }
        if(root->val == y){
            ypos = cur;
            yparent = parent;
        }

        findVal(root->left, cur + 1, level, x, y, xpos, ypos, xparent, yparent, root);
        findVal(root->right, cur + 1, level, x, y, xpos, ypos, xparent, yparent, root);

        if(xpos == level && ypos == level && xparent != yparent) 
            return true;
        return false;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int n = level(root);
        for(int i = 1; i <= n; i++){
            int xpos = -1, ypos = -1;
            TreeNode* xparent = NULL;
            TreeNode* yparent = NULL;
            if(findVal(root, 1, i, x, y, xpos, ypos, xparent, yparent, NULL)) 
                return true;
        }
        return false;
    }
};
