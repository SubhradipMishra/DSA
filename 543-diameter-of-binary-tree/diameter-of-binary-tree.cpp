
class Solution {
private: int maxPath = INT_MIN ; 
private: int findNoOfNodes(TreeNode* root){
 if(!root) return  0 ; 
 return 1 + max(findNoOfNodes(root->left )  , findNoOfNodes(root->right)); 

}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL )  return  0  ;
        int ans =  findNoOfNodes(root->left) + findNoOfNodes(root->right) ; 
        if(maxPath < ans)  maxPath =  ans  ;
        
        diameterOfBinaryTree(root->left) ;
        diameterOfBinaryTree(root->right) ;

        return maxPath ; 

    }
};