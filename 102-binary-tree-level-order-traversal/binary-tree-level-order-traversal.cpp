
class Solution {
public:
 int level(TreeNode* root ){
    if(root == NULL) return 0 ;
    
    return 1 + max(level(root->left) ,level(root->right))  ;
       
 }


void l_order(TreeNode* root , vector<vector<int>>& ans,int l)  {
     if(root == NULL) return ; 
     ans[l].push_back(root->val); 

    l_order(root->left,ans,l+1);
    l_order(root->right,ans,l+1);
}



    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans ; 
          int n  = level(root) ;
            for(int  i  = 1 ; i <= n  ; i++ ) {
                vector<int>v;
             
                ans.push_back(v);
            }
        l_order(root,ans,0) ; 
        return ans ; 
    }
};