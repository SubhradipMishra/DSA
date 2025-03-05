#include<iostream> 
#include<queue>
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

 int level(Node* root ){
    if(root == NULL) return 0 ;
    
    return 1 + max(level(root->left) ,level(root->right))  ;
       
 }
void display_nth_node(Node* root , int cur , int level) {
if(root == NULL)  return ; 
if(cur == level ) {
    
    cout << root->val << " " ;
    return ; 
      }

display_nth_node(root->right ,cur+1 , level) ; 
display_nth_node(root->left , cur+1 , level ) ; 



  
 
}


void level_order(Node* root) {
int n  = level(root) ;
for(int  i  = 1 ; i <= n  ; i++ ) {
display_nth_node(root,1,i) ; 
}
}

void level_order_queue(Node* root){
  queue<Node*> q; 
  q.push(root); 
  while(q.size() > 0 ) {
    Node* temp = q.front()  ;
    q.pop() ;
    cout <<  temp->val << " " ; 
      if(temp->right !=  NULL  ) { 
      q.push(temp->right) ; 
    }
    
    if(temp->left !=  NULL  ) { 
      q.push(temp->left)  ; 
    }
   
  }
  
  
  
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

//  level_order(a); 
//  cout <<  endl ; 
 level_order_queue(a);

  
  
}