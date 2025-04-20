
class Solution {
public:
   int check(TreeNode* root){
     if(root == NULL )  return 0 ; 
     int l = check(root->left)  ; 
     if( l == -1) return -1;
     
     int r = check(root->right)  ; 
     if( r == -1) return -1;

     if(abs(l-r) > 1)  return -1;
     else return max(l,r)+1 ;


   }
    bool isBalanced(TreeNode* root) {
        if(check(root)!=-1) return true ; 
        else return false ; 
    }
};