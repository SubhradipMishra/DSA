
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans ; 
         if (!root) return ans;
        queue<TreeNode*>q   ;
        q.push(root);
        while(!q.empty()){
           int n = q.size() ; 
           vector<int>v ; 
           for(int i  = 0 ;  i <  n ;i++){
              TreeNode* node = q.front();
              q.pop();  
              v.push_back(node->val) ;
              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);

           }
           ans.push_back(v[v.size()-1]);

        }


return ans ;
    }
};