#include<iostream>
using namespace std  ; 
class Node { 
    public:
    int val ; 
    Node* next  ; 

    Node(int val){
       this -> val = val ; 
         this -> next  =  NULL   ;
    }

} ;

class LinkedList {
    public:
    Node* End ; 
    Node* tail ; 
    int size ; 

    LinkedList(){
        End = NULL ; 
        tail = NULL ; 
        size = 0 ; 

    }

    void insertAtEnd(int val) {
        Node* temp = new Node(val) ; 
        if(size == 0 ) 
         End = tail = temp ; 
        else{
             tail-> next = temp ; 
             tail  = temp ; 

        }
        size++ ;
    }

    void display() {
        Node* temp = End ;
         while(temp!=NULL){
            cout <<  temp->val << " " ;
            temp  =  temp -> next  ; 
         }
    }
};




int main() {
    LinkedList ll ; 
    ll.insertAtEnd(50) ; 
    ll.insertAtEnd(40) ; 
    ll.insertAtEnd(30) ; 

    ll.display() ; 

}