
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p ==  NULL && q == NULL )  return  true; 
      if( p == NULL && q!= NULL  ) return false; 
      if( p != NULL && q == NULL  ) return false;  
      if(p ->val != q->val)  return false ; 

      bool l = isSameTree(p->left , q->left) ; 
      if(!l) return false ; 

      bool r = isSameTree(p->right , q->right) ; 
      if(!r) return false ; 

      return true ;
    }
};