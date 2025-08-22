
class Solution {
public: TreeNode* helper(TreeNode* root  , int val){
    if(!root) return nullptr ; 
    if(root->val == val) return root ; 
    
    if(root->val > val )return helper(root->left,val) ; 
    else return helper(root->right  ,val) ;
}
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr ; 
        return helper(root  , val) ;
     }
};