
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st ;
        vector<int> ans ; 
        if(root ) st.push(root) ; 

        while(st.size() > 0 ) {
            TreeNode* temp = st.top() ; 
            st.pop() ; 
            if(temp->right) st.push(temp->right) ;
             if(temp->left) st.push(temp->left) ;
             ans.push_back(temp->val) ;
        }

        return ans ; 
    }
};