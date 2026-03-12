
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans ; 
        queue<TreeNode*>q ;
        q.push(root);
        while(!q.empty()){
            int s = q.size() ;
            vector<int>v ; 
            for(int i = 0 ; i < s ;i++){
              TreeNode* node = q.front() ;
              q.pop() ;
              v.push_back(node->val);
              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);
            }
            ans.push_back(v);
        }

        return ans ;
    }
};