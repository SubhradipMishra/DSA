
class Solution {
public:
  void helper(TreeNode* root , vector<int>& v){
    if(!root) return ; 
    helper(root->left , v)  ; 
    v.push_back(root->val)  ; 
    helper(root->right ,v) ; 
  }
    bool isValidBST(TreeNode* root) {
        vector<int>v ; 
        helper(root ,v) ; 
        for(int  i = 1 ;  i < v.size()  ; i++){
            if(v[i] <= v[i-1]) return false;  
        }

        return true ; 
    }
};