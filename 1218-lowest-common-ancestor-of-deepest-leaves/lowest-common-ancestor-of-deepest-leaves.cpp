
class Solution {
public:
     int depth(TreeNode* root){
        if(root==NULL)return 0; 
        int l=depth(root->left); 
        int r=depth(root->right); 
         return max(l,r)+1;
     }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int retl = depth(root->left) ,retr  = depth(root->right) ;
        if(retl  == retr)  return root ; 

      else if(retl > retr) root = root->left ; 
       else if(retl < retr) root = root->right ; 
       return lcaDeepestLeaves(root)  ;
    }

};