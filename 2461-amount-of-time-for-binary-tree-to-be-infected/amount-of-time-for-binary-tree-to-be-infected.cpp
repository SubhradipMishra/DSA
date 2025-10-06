
class Solution {
public:
    void markParent(TreeNode* root , unordered_map<TreeNode*,TreeNode*>& parent ){
        queue<TreeNode*>q ;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node ; 
                q.push(node->left);
            }

            if(node->right){
                parent[node->right] = node ; 
                q.push(node->right);
            }
        }
    }
     TreeNode* findNode(TreeNode* root, int start) {
        if (!root) return nullptr;
        if (root->val == start) return root;
        TreeNode* left = findNode(root->left, start);
        if (left) return left;
        return findNode(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent ; 
        markParent(root , parent);
         unordered_map<TreeNode*,bool>visited ; 
         queue<TreeNode*> q;
         int dis = 0  ; 
             TreeNode* target = findNode(root, start); 
         q.push(target);
         visited[target] = true ; 
         while(!q.empty()){
            int size = q.size() ; 
            dis++ ;
            for(int i = 0 ; i < size;i++){
                TreeNode* node = q.front() ;
                q.pop() ;

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true ; 
                }

                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true ; 
                }

                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true ; 
                }

            

            }
         }

         return dis-1; 
    }
};