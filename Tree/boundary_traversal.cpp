#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(NULL), right(NULL) {}
};

Node* construct(int arr[], int n) {
    if (n == 0) return NULL;

    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);

    int i = 1;
    while (i < n) {
        Node* temp = q.front();
        q.pop();

        if (i < n && arr[i] != INT_MIN) {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        } else {
            temp->left = NULL;
        }
        i++;

        if (i < n && arr[i] != INT_MIN) {
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        } else {
            temp->right = NULL;
        }
        i++;
    }

    return root;
}
void right_boundary(Node *root) {
    if(root == NULL  ) return; 
    if(root->left == NULL && root->right == NULL ) return  ; 
 
    right_boundary(root->right) ; 
    if(root->right == NULL)right_boundary(root->left) ;
       cout << root->val  << " " ; 

}
void leaf_node(Node *root) { 
    if(root == NULL  ) return; 
    if(root->left == NULL && root->right == NULL )
    cout << root->val  << " " ; 
    leaf_node(root->left) ; 
    leaf_node(root->right) ;
}

void left_boundary (Node* root) {
    if(root == NULL  ) return; 
    if(root->left == NULL && root->right == NULL ) return  ; 
    cout << root->val  << " " ; 
    left_boundary(root->left) ; 
    if(root->left == NULL)left_boundary(root->right) ;


}
int main() {
    int arr[] = {1,2,3,4,5,INT_MIN , 6, 7,INT_MIN,8,INT_MIN,9,10,INT_MIN ,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,28,INT_MIN,INT_MIN};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = construct(arr, n);
   
    left_boundary(root) ;
   
    leaf_node(root) ; 
  
    right_boundary(root->right) ;
    
    return 0;
}