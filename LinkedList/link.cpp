#include<iostream>
using namespace std ; 
class Node {
    public:
    int val ; 
    Node *next  ;

    Node(int  val) {
        this-> val = val ; 
        this->next  = NULL ; 
    }
} ; 



int main() {
    // Node a(10)  ; 
    // Node b(20)  ; 
    // Node c(30)  ; 
    // Node d(40)  ; 

    // a.next=&b ; 
    // b.next=&c ; 
    // c.next=&d ; 
    // // d.next=NULL ; 

    // // PRINT THE VALUE OF a : - 
    // cout << a.val << endl ;
    
    // // PRINT THE VALUE OF b : - 
    // cout << (a.next)->val << endl ; 

    // //PRINT THE VALUE OF c:-

    // cout << ((a.next)->next) -> val << endl;

    // // PRINT THE VALUE OF d : 

    // cout << (((a.next)->next)->next) -> val << endl  ;

    // Node temp = a ; 

    // while(1) {
    //     cout << temp.val << endl  ;
    //     if(temp.next == NULL) break ; 
    //      temp = *(temp.next) ; 

  Node* a = new Node(10) ; 
  Node* b = new Node(20) ; 
  Node* c = new Node(30) ; 
  Node* d = new Node(40) ; 

  a->next = b ; 
  b->next = c ; 
  c->next = d ; 
  cout << (a->next)->val ; 
Node * temp = a; 
while(temp!=NULL){
    cout << t emp->val << "  " ; 
    temp = temp -> next  ;
}
    
}