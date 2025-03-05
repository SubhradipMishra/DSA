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
            // tail->next  = temp ; 
            // tail = temp ; 
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


    void display(){
       
    Node* temp  = head ; 
    while(temp!=NULL) {
        cout <<   temp ->  val  << "  " ; 
        temp  = temp -> next ; 
    }
  }
    
};









int main() {
    LinkedList  ll ; 
    ll.insertAtHead(20); 
    ll.insertAtEnd(30) ;
     ll.insertAtEnd(40) ;
       ll.insertAtHead(50); 

    ll.insertAtIndex(2,70) ; 
      ll.insertAtIndex(3,100) ; 
    ll.display() ; 
}