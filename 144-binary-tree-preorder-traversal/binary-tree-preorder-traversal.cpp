
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
         stack<TreeNode*>st ;
         vector<int>ans ; 
         if(root) st.push(root);
         while(!st.empty()){
            TreeNode* k = st.top() ;
            st.pop() ; 
            ans.push_back(k->val);
            if(k->right)st.push(k->right);
            if(k->left)st.push(k->left);
             
         }

         return ans ; 
    }
};