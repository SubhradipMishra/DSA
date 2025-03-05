#include<iostream>
using namespace std ; 

class Node{  
     public:
     int val ; 
     Node *next ; 


     Node (int val ){
        this-> val = val ; 
        this -> next = NULL ; 

     }

    

} ; 

//  void display(Node *head ){
//         while(head != NULL ) {
//             cout <<  head -> val << " "  ; 
//              head  = head->next  ;
//         }
//      }


void display(Node *head ){
    if(head == NULL ) return  ; 
      display(head->next) ; 
    cout <<  head->val << " "   ;
  
}


int main() {
     Node*  a  = new Node(10) ; 
     Node*  b = new Node(30) ; 
     Node*  c  = new Node(50) ; 
     Node*  d  = new Node(70) ; 

     a -> next  = b ; 
     b -> next = c ; 
     c -> next  = d ; 

    display(a) ; 

}