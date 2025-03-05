#include<iostream>
using namespace std ; 
class Node {
    public:
    int val ; 
    Node* next   ; 
    Node(int val ) {
       this-> val = val   ; 
       this-> next  = NULL;  

    } 
} ; 


class LinkedList {

    public:
    Node *head ; 
    Node *tail ; 
    int size ; 

    LinkedList() {
        this-> head = NULL ; 
        this-> tail = NULL ; 
        this-> size = 0 ; 

    }

    void insertAtEnd(int val  ){
        Node* temp =  new Node(val) ; 
        if(size == 0 ) head = tail =temp ; 

        else{
            tail->next  = temp ; 
            tail = temp ; 

        }

        size++ ; 
    }

    void insertAtHead(int val  ){
        Node* temp =  new Node(val) ; 
        if(size == 0 ) head = tail =temp ; 

        else{
            
             temp->next = head ; 
             head = temp ; 
        }

        size++ ; 
    }

    void insertAtIndex(int idx,  int val ) {
    
        if(idx < 0 ||  idx>size )  cout << "Invalid index"<< endl  ; 
        else if(idx == 0 ) insertAtHead(val) ; 
        else if(idx == size ) insertAtEnd(val) ; 
        else{
                Node * t = new Node(val) ;  
                Node *temp = head ; 
           for(int i =  1 ;  i <= idx-1 ;i++) {
                 temp = temp->next ; 
           }
           t-> next = temp->next  ; 
           temp->next = t ;
           size++ ; 
        }
    }

    void deleteAtHead() {
        if(size ==  0 ) 
        {
            cout << " The list is empty: " << endl; 
            return ; 

        }

        head = head->next ; 
        size--; 
    }

   void deleteAtTail(){
    if(size == 0 ) {
        cout << "The list is empty " << endl ; 
        return ;  
    }

    Node* temp = head ; 

    while(temp->next != tail ) {
       temp = temp->next ; 
    }

    temp->next = NULL ; 
    tail = temp ; 
    size--  ;

   }

   void deleteAtIndex(int idx) {
     if(idx < 0 ||  idx>=size ) {
        cout << "Invalid" << endl ;
        return ;  
     }
     else if(idx == 0 ) return deleteAtHead(); 
     else if(idx == size-1)  return deleteAtTail() ; 
     else {
        Node* temp = head ; 
       for(int i  = 1 ; i<=idx-1 ; i++ ) {
       temp = temp->next ; 
       }
       temp->next =  temp->next->next ; 
       size--; 
     }
   }


    void display(){
       
    Node* temp  = head ; 
    while(temp!=NULL) {
        cout <<   temp ->  val  << "  " ; 
        temp  = temp -> next ; 
    }
      cout << endl; 

  }

  
  
    
};









int main() {
    LinkedList  ll ; 
    ll.insertAtHead(20); 
    ll.display() ;
    ll.insertAtEnd(30) ;
    ll.display() ;
     ll.insertAtEnd(40) ;
     ll.display() ;
       ll.insertAtHead(50); 
       ll.display() ;

    ll.insertAtIndex(2,70) ; 
    ll.display() ;
      ll.insertAtIndex(3,100) ; 
    ll.display() ;
    ll.deleteAtHead() ; 
    ll.display() ;
     ll.deleteAtTail() ; 
    ll.display() ;

     ll.deleteAtIndex(2) ; 
    ll.display() ;

}