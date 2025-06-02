
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
       ListNode* even = new ListNode(-1) ; 
       ListNode* odd = new ListNode(-1); 
       ListNode* tEven = even ;
       ListNode* tOdd = odd ;  
       ListNode* temp = head;  
       int i =  1 ; 
       while(temp){
        if(i %2!=0){
            tOdd ->next = temp ; 
            tOdd =  temp ; 
        }
        else{
            tEven->next = temp ; 
            tEven = temp ; 
        }
        temp = temp->next ; 
        i++ ; 
       }


       tOdd ->next = even->next ; 
       tEven->next = nullptr ; 
       return odd->next ; 

    }
};