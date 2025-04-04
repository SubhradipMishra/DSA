
class Solution {
public:
int depth(TreeNode* root){
    if(root == NULL )  return  0 ;
    int r = depth(root->right) ;
    int l = depth(root->left)  ;

    return max(l,r)+1 ; 

}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {


     int r = depth(root->right) ;
     int l = depth(root->left)  ;

        if(l == r)  return root ; 
       else if(l  > r ) root = root->left  ;
       else if(r > l ) root = root->right ; 
        

        return lcaDeepestLeaves(root) ;  
        
            }
};