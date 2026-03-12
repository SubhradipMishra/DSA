
class Solution {

    int maxi  = INT_MIN ; 
    int findNoOfNode(TreeNode* root){
        if(root == NULL)  return 0 ;
        return 1 + max(findNoOfNode(root->left) , findNoOfNode(root->right));  
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       if(root == NULL) return 0 ;
       int ans = findNoOfNode(root->left) + findNoOfNode(root->right)  ;
       maxi = max(maxi , ans);

       diameterOfBinaryTree(root->left) ;
        diameterOfBinaryTree(root->right) ;


        return maxi ; 

    }
};