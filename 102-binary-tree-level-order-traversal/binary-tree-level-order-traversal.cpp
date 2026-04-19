
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q ;
        if(!root) return{} ; 
    
        vector<vector<int>>ans ;
        q.push(root) ;
        while(!q.empty()){
            int n = q.size() ;
            vector<int>v ;  
            for(int i = 0 ;  i < n  ; i++){
                TreeNode* x = q.front() ; 
                q.pop() ;
                v.push_back(x->val) ; 
                if(x->left) q.push(x->left) ; 
                if(x->right) q.push(x->right) ;
            }
            ans.push_back(v) ; 
        }

        return ans ; 
    }
};