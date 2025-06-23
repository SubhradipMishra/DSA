
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
     
        int n =  0 ;
        ListNode* temp  = head ; 

        // find the length of the list

        while(temp){
            n++ ; 
            temp = temp->next ; 

        }

        if( n == k  ) return head->next; 

        // now we find the element which is just before the element whichh is need to delete
          temp = head ; 
        for(int i  =  1 ; i <= n - k -1  ; i++ ){
           temp = temp->next ; 
        }

        temp->next  = temp->next->next ; 


        return head ; 
    }
};