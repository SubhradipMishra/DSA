#include<iostream> 
using namespace std ; 
class Node {
    public:
    int val; 
    Node* left ; 
    Node* right; 

    Node(int val) {
      this->val = val ;
      this->right = NULL ;
      this->left = NULL;
    }
} ; 
 int sumofNodes(Node* root ){
    if(root == NULL) return 0 ;
    int ans = sumofNodes(root->left ) + sumofNodes(root->right)  +root-> val; 
    return ans ; 
 }

int main() {
  Node* a = new Node(1) ; //  root Node ; 
  Node* b = new Node(2) ;
  Node* c = new Node(3) ;
  Node* d = new Node(4) ;
  Node* e = new Node(5) ;
  Node* f = new Node(6) ;
  Node* g = new Node(7) ;
  a->left =  b ; 
  a->right = c ; 
  b->left  = d ; 
  b->right = e ; 
  c->left  = f ; 
  c->right = g ; 

  
  cout << sumofNodes(a) <<endl; 
}