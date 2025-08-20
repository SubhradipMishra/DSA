
class Solution {
public:
    TreeNode* build(vector<int>& pre ,int plo , int phi  ,  vector<int>& in  , int ilo , int ihi){
     if(plo > phi )  return NULL ; 
     TreeNode* root = new TreeNode(pre[plo] ); 
     if(plo == phi)  return root ; 

     // find the root in the 'in-order' 

     int i  = ilo ;// pointer to traverse and find the root in the in-order and we store the index also in this 'i'
     while( i <= ihi){
        if(in[i] == root->val) break ; 
        i++ ; 
     }

     int leftCount = i - ilo ; 
     int rightCount =  i - ihi ; 

     root->left = build(pre  , plo + 1 , plo + leftCount , in , ilo,  i-1 ) ;
     root->right = build(pre , plo + leftCount+1  , phi , in , i+1 ,  ihi) ; 

     return root  ; 

    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
     int n =  pre.size();    
     return build(pre  ,  0 , n -1 , in  , 0 , n-1) ; 
    }
};