
class Solution {
public:
bool isExist(TreeNode* root , TreeNode* p){
    if(root == NULL ) return false ;
    if(root == p ) return true  ;

    return isExist(root->left ,p) || isExist(root->right , p );
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)  return  root ; 
        else if(isExist(root->left ,p ) && isExist(root->right ,q)) return root ;
        else if (!isExist(root ->left,p ) && !isExist(root->right ,q)) return root ;
        else if(isExist(root->left, p) && !isExist(root->right,q)) return lowestCommonAncestor(root->left , p,q);

        else return lowestCommonAncestor(root->right , p,q);
    }
};