
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true ; 
        if(!p && q  || !q && p  || p->val != q->val ) return false; 
        bool l = isSameTree(p->left , q->left);
        if( l == false ) return false ; 

        bool r = isSameTree(p->right ,q->right);
        if(r== false) return false ;


        return true ; 

    }
};